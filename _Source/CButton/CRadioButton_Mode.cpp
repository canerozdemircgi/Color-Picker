#include "CRadioButton_Mode.h"

#include "../CMacro/CSignal.h"

int CRadioButton_Mode::indexSelected = 0;

CRadioButton_Mode::CRadioButton_Mode(const int index, QWidget *__restrict__ parent) :
	QRadioButton(parent),
	index(index),
	Toggled(nullptr)
{
}

void CRadioButton_Mode::checkStateSet()
{
	QRadioButton::checkStateSet();
	if(Toggled != nullptr)
		jump Toggled();
}

void CRadioButton_Mode::nextCheckState()
{
	QRadioButton::nextCheckState();
	jump Toggled();
}