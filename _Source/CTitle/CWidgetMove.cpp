#include "CWidgetMove.hpp"

#include <QtGui/QWindow>

using namespace Qt::Literals::StringLiterals;

CWidgetMove::CWidgetMove(QWidget* const parent) :
	QWidget{parent},

	active{false}
{
	this->setAccessibleName(u"CWidgetMove"_s);
}

void CWidgetMove::mouseMoveEvent(QMouseEvent* const event)
{
	QWidget::mouseMoveEvent(event);

	if (!this->active)
	{
		this->active = true;
		this->window()->windowHandle()->startSystemMove();
	}
}

void CWidgetMove::mouseReleaseEvent(QMouseEvent* const event)
{
	if (this->active)
		this->active = false;

	QWidget::mouseReleaseEvent(event);
}

void CWidgetMove::mouseDoubleClickEvent(QMouseEvent* const event)
{
	QWidget::mouseDoubleClickEvent(event);

	this->mouseDoubleClicked();
}