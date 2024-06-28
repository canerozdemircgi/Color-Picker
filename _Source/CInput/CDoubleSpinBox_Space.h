#ifndef CDoubleSpinBox_Space_H
#define CDoubleSpinBox_Space_H

#include "CDoubleSpinBox.h"

class CDoubleSpinBox_Space : public CDoubleSpinBox
{
	Q_OBJECT

public:
	explicit CDoubleSpinBox_Space(const int limitMin, const int limitMax, QWidget *__restrict__ parent);

	void RefreshState();

	void SetLimit(const int limitMin, const int limitMax);

private:
    GetAccessorPrivate(int, limitMin, LimitMin)
    GetAccessorPrivate(int, limitMax, LimitMax)

	QString textFromValue(const double value) const override;

public slots:
	void ValueChanged(const double result);
};

#endif