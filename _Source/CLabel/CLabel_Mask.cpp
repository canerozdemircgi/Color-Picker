#include "CLabel_Mask.h"

CLabel_Mask::CLabel_Mask(QWidget *__restrict__ parent) :
	QLabel(parent),

	pixmap(QPixmap(":/Target/Mask.svg").scaled(30, 30, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation))
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