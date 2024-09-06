#include "CPushButton_Sta.h"

#include "../CMacro/CSignal.h"

CPushButton_Sta::CPushButton_Sta(QWidget *__restrict__ parent) :
	QPushButton(parent),

	MouseLeftReleased(nullptr),
	MouseRightReleased(nullptr),
	MouseMiddleReleased(nullptr)
{
}

void CPushButton_Sta::mouseReleaseEvent(QMouseEvent *__restrict__ event)
{
	clearFocus();

	if (event->button() == Qt::MouseButton::LeftButton && MouseLeftReleased != nullptr)
		jump MouseLeftReleased();
	else if (event->button() == Qt::MouseButton::RightButton && MouseRightReleased != nullptr)
		jump MouseRightReleased();
	else if (event->button() == Qt::MouseButton::MiddleButton && MouseMiddleReleased != nullptr)
		jump MouseMiddleReleased();
}