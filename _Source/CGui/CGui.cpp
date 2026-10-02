#include "CGui.hpp"

#include <QtGui/QScreen>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>

void CGui::makeFrameless(QWidget* const widget, Qt::WindowType windowType) noexcept
{
	widget->setWindowFlags(windowType | Qt::WindowType::FramelessWindowHint);

	widget->setAttribute(Qt::WidgetAttribute::WA_TranslucentBackground);

	#ifdef _WIN32
	widget->setProperty("C", true);
	#endif
}

QWidget* CGui::window() noexcept
{
	for (const QList<QWidget*> widgets = QApplication::topLevelWidgets(); QWidget* const widget : widgets)
	{
		if (widget->windowType() == Qt::WindowType::ToolTip)
			continue;
		return widget;
	}
	return nullptr;
}

QRect CGui::availableGeometryCurrentScreen() noexcept
{
	return QGuiApplication::screenAt(QCursor::pos())->availableGeometry();
}

QRect CGui::availableGeometryAllScreens() noexcept
{
	QRect rect;
	for (const QScreen* const screen : QGuiApplication::screens())
		rect |= screen->availableGeometry();
	return rect;
}

void CGui::setGeometryMinimumCenter(QWidget* const widget) noexcept
{
	CGui::invalidateLayout(widget);

	QMetaObject::invokeMethod(widget, [](QWidget* const widget) noexcept
	{
		const QWidget* const parent = widget->parentWidget();
		const QPoint center = parent ? parent->geometry().center() : CGui::availableGeometryCurrentScreen().center();
		const QRect rectMinimum(QPoint(), widget->minimumSizeHint());
		widget->setGeometry(rectMinimum.translated(center - rectMinimum.center()));
	}, Qt::ConnectionType::QueuedConnection, widget);
}

void CGui::invalidateLayout(const QWidget* const widget) noexcept
{
	QList<const QWidget*> children = widget->findChildren<const QWidget*>();
	children.append(widget);
	for (const QWidget* const child : children)
	{
		if (QLayout* const layout = child->layout())
			layout->invalidate();
	}
}