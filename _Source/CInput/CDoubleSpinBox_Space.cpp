#include "CDoubleSpinBox_Space.h"

#include "../CGeneral/CCore.h"

#include <cmath>

CDoubleSpinBox_Space::CDoubleSpinBox_Space(const int limitMin, const int limitMax, QWidget *__restrict__ parent) :
	CDoubleSpinBox(std::max(std::abs(limitMin), limitMax), parent),

	limitMin(limitMin),
	limitMax(limitMax)
{
}

QString CDoubleSpinBox_Space::textFromValue(const double value) const
{
	const QString result = stateDouble ?
		QString("%1").arg(value, 0, 'f', precision, QLatin1Char('0')) :
		QString::number(value);
	return value > 0.0 ? '+' + result : result;
}

void CDoubleSpinBox_Space::ValueChanged(const double result)
{
	if (stateDouble)
	{
		if (stateGamma)
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

	if (stateDouble)
	{
		setDecimals(precision);
		setSingleStep(1.0 / pow(10.0, precision));

		setMinimum(static_cast<double>(limitMin) / limit);
		setMaximum(static_cast<double>(limitMax) / limit);
	}
	else
	{
		setDecimals(0);
		setSingleStep(1.0);

		setMinimum(limitMin);
		setMaximum(limitMax);
	}
	RefreshResult();

	blockSignals(false);
}

void CDoubleSpinBox_Space::SetLimit(const int limitMin, const int limitMax)
{
	this->limitMin = limitMin;
	this->limitMax = limitMax;
	limit = std::max(std::abs(limitMin), limitMax);

	blockSignals(true);

	if (stateDouble)
	{
		setMinimum(static_cast<double>(limitMin) / limit);
		setMaximum(static_cast<double>(limitMax) / limit);
	}
	else
	{
		setMinimum(limitMin);
		setMaximum(limitMax);
	}

	blockSignals(false);
}