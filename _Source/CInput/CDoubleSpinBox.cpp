#include "CDoubleSpinBox.h"

#include "../CGeneral/CCore.h"

bool CDoubleSpinBox::stateDouble = false;
int CDoubleSpinBox::precision;

bool CDoubleSpinBox::stateGamma = false;
double CDoubleSpinBox::gamma;

CDoubleSpinBox::CDoubleSpinBox(const int limit, QWidget *__restrict__ parent) :
	QDoubleSpinBox(parent),

	limit(limit),
	result(0)
{
}

void CDoubleSpinBox::SetResult(const int result)
{
	this->result = result;
	RefreshResult();
}

void CDoubleSpinBox::RefreshResult()
{
	blockSignals(true);

	if (stateDouble)
	{
		if (stateGamma)
			setValue(CCore::PowFull(static_cast<double>(result) / static_cast<double>(limit), gamma));
		else
			setValue(static_cast<double>(result) / static_cast<double>(limit));
	}
	else
		setValue(static_cast<double>(result));

	blockSignals(false);
}