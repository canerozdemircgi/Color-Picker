#ifndef CMenu_Main_H
#define CMenu_Main_H

#include <QtWidgets/QMenu>

class CMenu_Main : public QMenu
{
public:
	explicit CMenu_Main(QWidget *__restrict__ parent);
	void Show(const QPoint &__restrict__ pos);
};

#endif