#include "CMenu_Main.h"

CMenu_Main::CMenu_Main(QWidget *__restrict__ parent) :
	QMenu(parent)
{
}

void CMenu_Main::Show(const QPoint &__restrict__ pos)
{
	move(pos);
	show();
}