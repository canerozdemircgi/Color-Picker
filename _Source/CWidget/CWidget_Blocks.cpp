#include "CWidget_Blocks.h"

CWidget_Blocks::CWidget_Blocks(QWidget *__restrict__ parent) :
	QWidget(parent),

	Checker_QLabel(this),

	XBlock_QWidget(this),
	YBlock_QWidget(this),
	ZBlock_QWidget(this),
	WBlock_QWidget(this)
{
	Checker_QLabel.setGeometry(120, 0, 40, 400);
	Checker_QLabel.setPixmap(QPixmap(":/Checker/Block.svg"));

	XBlock_QWidget.setGeometry(0, 0, 40, 400);
	YBlock_QWidget.setGeometry(40, 0, 40, 400);
	ZBlock_QWidget.setGeometry(80, 0, 40, 400);
	WBlock_QWidget.SetEnabled(false);
	WBlock_QWidget.setGeometry(120, 0, 40, 400);
}