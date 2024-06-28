#include "CLabel_Mask.h"

CLabel_Mask::CLabel_Mask(QWidget *__restrict__ parent) :
	QLabel(parent),

	pixmap(QPixmap(":/Target/2 Small.svg"))
{
	setPixmap(pixmap);
}

void CLabel_Mask::enterEvent(QEnterEvent *__restrict__)
{
	clear();
}

void CLabel_Mask::leaveEvent(QEvent *__restrict__)
{
	setPixmap(pixmap);
}