#ifndef CDoubleSpinBox_Space_H
#define CDoubleSpinBox_Space_H

#include "CDoubleSpinBox.h"

class CDoubleSpinBox_Space : public CDoubleSpinBox
{
	Q_OBJECT

public:
	explicit CDoubleSpinBox_Space(const int limit, QWidget *__restrict__ parent);

	void RefreshState();

	void SetLimit(const int limit);

private:
	QString textFromValue(const double value) const override;

public slots:
	void ValueChanged(const double result);
};

#endif