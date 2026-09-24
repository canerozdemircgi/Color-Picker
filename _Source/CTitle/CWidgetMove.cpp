#include "CWidgetMove.hpp"

#include <QtGui/QWindow>

using namespace Qt::Literals::StringLiterals;

CWidgetMove::CWidgetMove(QWidget* const parent) noexcept :
	QWidget{parent},

	active{false},
	mouseDoubleClick{false}
{
	this->setAccessibleName(u"CWidgetMove"_s);
}

void CWidgetMove::mouseMoveEvent(QMouseEvent* const event) noexcept
{
	QWidget::mouseMoveEvent(event);

	if (!this->active)
	{
		this->active = true;
		this->window()->windowHandle()->startSystemMove();
	}
}

void CWidgetMove::mouseReleaseEvent(QMouseEvent* const event) noexcept
{
	if (this->mouseDoubleClick)
	{
		this->mouseDoubleClick = false;
		this->mouseDoubleClicked();
	}
	else
	{
		if (this->active)
			this->active = false;
	}

	QWidget::mouseReleaseEvent(event);
}

void CWidgetMove::mouseDoubleClickEvent(QMouseEvent* const event) noexcept
{
	QWidget::mouseDoubleClickEvent(event);

	this->mouseDoubleClick = true;
}