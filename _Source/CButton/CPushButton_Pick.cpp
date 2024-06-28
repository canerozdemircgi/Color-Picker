#include "CPushButton_Pick.h"

#include "../CMacro/CSignal.h"
#include "../CWindow/CMagnifier.h"

CPushButton_Pick::CPushButton_Pick(QWidget *__restrict__ parent) :
	QPushButton(parent)
{
}

void CPushButton_Pick::mousePressEvent(QMouseEvent *__restrict__ event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
		jump MouseLeftPressed();
	else if (event->button() == Qt::MouseButton::RightButton)
		jump MouseRightPressed();
	else if (event->button() == Qt::MouseButton::MiddleButton)
		jump MouseMiddlePressed();
}

void CPushButton_Pick::mouseMoveEvent(QMouseEvent *__restrict__ event)
{
    QPushButton::mouseMoveEvent(event);

    if (event->buttons())
	    jump MouseMoved();
}

void CPushButton_Pick::mouseReleaseEvent(QMouseEvent *__restrict__)
{
	jump MouseReleased();
}