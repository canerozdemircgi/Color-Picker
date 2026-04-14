#include "CWidgetSize.hpp"

#include <QtGui/QWindow>

using namespace Qt::Literals::StringLiterals;

const CWidgetSize::Direction CWidgetSize::Direction::BOTTOM_LEFT =
{
	u"BottomLeft"_s,
	Qt::Edge::BottomEdge | Qt::Edge::LeftEdge,
	Qt::CursorShape::SizeBDiagCursor,
	[](QWidget* const widget)
	{
		widget->move(QPoint(0, widget->window()->windowHandle()->height() - widget->height()));
	}
};

const CWidgetSize::Direction CWidgetSize::Direction::BOTTOM_RIGHT =
{
	u"BottomRight"_s,
	Qt::Edge::BottomEdge | Qt::Edge::RightEdge,
	Qt::CursorShape::SizeFDiagCursor,
	[](QWidget* const widget)
	{
		widget->move(QPoint(widget->window()->windowHandle()->width() - widget->width(), widget->window()->windowHandle()->height() - widget->height()));
	}
};

CWidgetSize::CWidgetSize(QWidget* const parent, const CWidgetSize::Direction& direction) :
	QWidget{parent},

	direction{direction},
	active{false}
{
	this->setProperty("hasNoBackground", true);

	this->setAccessibleName(u"CWidgetSize%1"_s.arg(direction.name));
	this->setCursor(this->direction.cursor);

	this->setFixedSize(15, 15);
}

void CWidgetSize::move()
{
	this->direction.move(this);
}

void CWidgetSize::showEvent(QShowEvent* const event)
{
	QWidget::showEvent(event);

	this->raise();
}

void CWidgetSize::mouseMoveEvent(QMouseEvent* const event)
{
	QWidget::mouseMoveEvent(event);

	if (!this->active)
	{
		this->active = true;
		this->window()->windowHandle()->startSystemResize(this->direction.edges);
	}
}

void CWidgetSize::mouseReleaseEvent(QMouseEvent* const event)
{
	if (this->active)
		this->active = false;

	QWidget::mouseReleaseEvent(event);
}