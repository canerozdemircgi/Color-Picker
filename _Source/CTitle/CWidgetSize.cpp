#include "CWidgetSize.hpp"

#include <QtGui/QWindow>

using namespace Qt::Literals::StringLiterals;

const CWidgetSize::Direction CWidgetSize::Direction::TOP =
{
	u"Top"_s,
	Qt::Edge::TopEdge,
	Qt::CursorShape::SizeVerCursor,
	[](QWidget& widget)
	{
		widget.move(QPoint((widget.window()->windowHandle()->width() - widget.width()) / 2, 0));
	}
};

const CWidgetSize::Direction CWidgetSize::Direction::BOTTOM =
{
	u"Bottom"_s,
	Qt::Edge::BottomEdge,
	Qt::CursorShape::SizeVerCursor,
	[](QWidget& widget)
	{
		widget.move(QPoint((widget.window()->windowHandle()->width() - widget.width()) / 2, widget.window()->windowHandle()->height() - widget.height()));
	}
};

const CWidgetSize::Direction CWidgetSize::Direction::LEFT =
{
	u"Left"_s,
	Qt::Edge::LeftEdge,
	Qt::CursorShape::SizeHorCursor,
	[](QWidget& widget)
	{
		widget.move(QPoint(0, (widget.window()->windowHandle()->height() - widget.height()) / 2));
	}
};

const CWidgetSize::Direction CWidgetSize::Direction::RIGHT =
{
	u"Right"_s,
	Qt::Edge::RightEdge,
	Qt::CursorShape::SizeHorCursor,
	[](QWidget& widget)
	{
		widget.move(QPoint(widget.window()->windowHandle()->width() - widget.width(), (widget.window()->windowHandle()->height() - widget.height()) / 2));
	}
};

const CWidgetSize::Direction CWidgetSize::Direction::TOP_LEFT =
{
	u"TopLeft"_s,
	Qt::Edge::TopEdge | Qt::Edge::LeftEdge,
	Qt::CursorShape::SizeFDiagCursor,
	[](QWidget& widget)
	{
		widget.move(QPoint(0, 0));
	}
};

const CWidgetSize::Direction CWidgetSize::Direction::TOP_RIGHT =
{
	u"TopRight"_s,
	Qt::Edge::TopEdge | Qt::Edge::RightEdge,
	Qt::CursorShape::SizeBDiagCursor,
	[](QWidget& widget)
	{
		widget.move(QPoint(widget.window()->windowHandle()->width() - widget.width(), 0));
	}
};

const CWidgetSize::Direction CWidgetSize::Direction::BOTTOM_LEFT =
{
	u"BottomLeft"_s,
	Qt::Edge::BottomEdge | Qt::Edge::LeftEdge,
	Qt::CursorShape::SizeBDiagCursor,
	[](QWidget& widget)
	{
		widget.move(QPoint(0, widget.window()->windowHandle()->height() - widget.height()));
	}
};

const CWidgetSize::Direction CWidgetSize::Direction::BOTTOM_RIGHT =
{
	u"BottomRight"_s,
	Qt::Edge::BottomEdge | Qt::Edge::RightEdge,
	Qt::CursorShape::SizeFDiagCursor,
	[](QWidget& widget)
	{
		widget.move(QPoint(widget.window()->windowHandle()->width() - widget.width(), widget.window()->windowHandle()->height() - widget.height()));
	}
};

CWidgetSize::CWidgetSize(QWidget* const parent, const CWidgetSize::Direction& direction) :
	QWidget{parent},

	direction{direction},
	active{false}
{
	this->setAccessibleName(u"CWidgetSize%1"_s.arg(direction.name));
	this->setCursor(this->direction.cursor);

	if (this->direction.cursor == Qt::CursorShape::SizeHorCursor || this->direction.cursor == Qt::CursorShape::SizeVerCursor)
		this->setFixedSize(40, 40);
	else
		this->setFixedSize(20, 20);
}

void CWidgetSize::move()
{
	this->direction.move(*this);
}

void CWidgetSize::showEvent(QShowEvent* const event)
{
	QWidget::showEvent(event);

	this->lower();
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