#ifndef CWidget_Blocks_H
#define CWidget_Blocks_H

#include "CWidget_Block.h"

class CWidget_Blocks : public QWidget
{
public:
	explicit CWidget_Blocks(QWidget *__restrict__ parent);

	QLabel Checker_QLabel;

	CWidget_Block XBlock_QWidget;
	CWidget_Block YBlock_QWidget;
	CWidget_Block ZBlock_QWidget;
	CWidget_Block WBlock_QWidget;
};

#endif