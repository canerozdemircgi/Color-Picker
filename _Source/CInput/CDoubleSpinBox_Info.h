#ifndef CDoubleSpinBox_Info_H
#define CDoubleSpinBox_Info_H

#include "CDoubleSpinBox.h"

#include <QtGui/QMouseEvent>

#include <functional>

class CDoubleSpinBox_Info : public CDoubleSpinBox
{
	Q_OBJECT

public:
	explicit CDoubleSpinBox_Info(const int limit, QWidget *__restrict__ parent);

	void RefreshState();

	std::function<void(const int)> ValueChangedNotBySet;

private:
	void stepBy(int step) override;
	void wheelEvent(QWheelEvent *__restrict__ event) override;

public slots:
	void ValueChanged(const double result);
};

#endif