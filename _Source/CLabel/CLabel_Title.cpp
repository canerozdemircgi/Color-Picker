#include "CLabel_Title.h"

CLabel_Title::CLabel_Title(QWidget *__restrict__ parent) :
	QLabel(parent),

	window(parent->window())
{
}

void CLabel_Title::mousePressEvent(QMouseEvent *__restrict__ event)
{
	setCursor(Qt::CursorShape::SizeAllCursor);
	posOld = event->pos();
}

void CLabel_Title::mouseMoveEvent(QMouseEvent *__restrict__ event)
{
	window->move(window->pos() + event->pos() - posOld);
}

void CLabel_Title::mouseReleaseEvent(QMouseEvent *__restrict__)
{
	setCursor(Qt::CursorShape::ArrowCursor);
}