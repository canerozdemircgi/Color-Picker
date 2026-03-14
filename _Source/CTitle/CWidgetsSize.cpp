#include "CWidgetsSize.hpp"

#include "CTitle/CWidgetSize.hpp"

#include <QtGui/QWindow>

CWidgetsSize::CWidgetsSize(QWidget* const parent) :
	QWidget(parent),

	instances
	({
		new CWidgetSize(parent, CWidgetSize::Direction::BOTTOM_LEFT),
		new CWidgetSize(parent, CWidgetSize::Direction::BOTTOM_RIGHT)
	})
{
	this->setEnabled(false);
	this->setFixedSize(0, 0);

	QWidget::setVisible(true);
}

void CWidgetsSize::setVisible(bool visible)
{
	for (CWidgetSize* const instance : this->instances)
		instance->setVisible(visible);
}

void CWidgetsSize::showEvent(QShowEvent* const event)
{
	QWidget::showEvent(event);

	this->window()->windowHandle()->installEventFilter(this);
}

bool CWidgetsSize::eventFilter(QObject* const object, QEvent* const event)
{
	const bool eventFilter = QWidget::eventFilter(object, event);

	if (event->type() == QEvent::Type::Resize)
	{
		for (CWidgetSize* const instance : this->instances)
			instance->move();
	}

	return eventFilter;
}