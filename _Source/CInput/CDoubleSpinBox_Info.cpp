#include "CDoubleSpinBox_Info.h"

#include "../CGeneral/CCore.h"
#include "../CMacro/CSignal.h"

CDoubleSpinBox_Info::CDoubleSpinBox_Info(const int limit, QWidget *__restrict__ parent) :
	CDoubleSpinBox(limit, parent)
{
}

void CDoubleSpinBox_Info::ValueChanged(const double result)
{
	if(stateDouble)
	{
		if(stateGamma)
			this->result = CCore::RoundToInt(CCore::PowFull(result, 1.0 / gamma) * static_cast<double>(limit));
		else
			this->result = CCore::RoundToInt(result * static_cast<double>(limit));
	}
	else
		this->result = static_cast<int>(result);

	jump ValueChangedNotBySet(this->result);
}

void CDoubleSpinBox_Info::RefreshState()
{
	blockSignals(true);

	if(stateDouble)
	{
		setDecimals(precision);
		setMaximum(1.0);
	}
	else
	{
		setDecimals(0);
		setMaximum(static_cast<double>(limit));
	}
	RefreshResult();

	blockSignals(false);
}

void CDoubleSpinBox_Info::wheelEvent(QWheelEvent *__restrict__ event)
{
	stepBy(event->angleDelta().y());
}

void CDoubleSpinBox_Info::stepBy(int step)
{
	if(step > 0)
	{
		if(result == limit)
			return;
		jump ValueChangedNotBySet(++result);
	}
	else if(step < 0)
	{
		if(result == 0)
			return;
		jump ValueChangedNotBySet(--result);
	}
}