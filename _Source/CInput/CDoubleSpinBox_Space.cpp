#include "CDoubleSpinBox_Space.h"

#include "../CGeneral/CCore.h"

#include <cmath>

CDoubleSpinBox_Space::CDoubleSpinBox_Space(const int limit, QWidget *__restrict__ parent) :
	CDoubleSpinBox(limit, parent)
{
}

QString CDoubleSpinBox_Space::textFromValue(const double value) const
{
	if(stateDouble)
	{
		const QString result(QString("%1").arg(value, 0, 'f', precision, QLatin1Char('0')));
		return value > 0.0 ? '+' + result : result;
	}
	else
	{
		const QString result(QString::number(value));
		return value > 0.0 ? '+' + result : result;
	}
}

void CDoubleSpinBox_Space::ValueChanged(const double result)
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
}

void CDoubleSpinBox_Space::RefreshState()
{
	blockSignals(true);

	if(stateDouble)
	{
		setDecimals(precision);
		setSingleStep(1.0 / pow(10.0, static_cast<double>(precision)));

		setMinimum(-1.0);
		setMaximum(1.0);
	}
	else
	{
		setDecimals(0);
		setSingleStep(1.0);

		setMinimum(static_cast<double>(-1 * limit));
		setMaximum(static_cast<double>(limit));
	}
	RefreshResult();

	blockSignals(false);
}

void CDoubleSpinBox_Space::SetLimit(const int limit)
{
	blockSignals(true);

	this->limit = limit;
	if(!stateDouble)
	{
		setMinimum(static_cast<double>(-1 * limit));
		setMaximum(static_cast<double>(limit));
	}

	blockSignals(false);
}