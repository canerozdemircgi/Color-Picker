#ifndef CDoubleSpinBox_H
#define CDoubleSpinBox_H

#include "../CMacro/CAccessor.h"

#include <QtWidgets/QDoubleSpinBox>

class CDoubleSpinBox : public QDoubleSpinBox
{
public:
	explicit CDoubleSpinBox(const int limit, QWidget *__restrict__ parent);

	static bool stateDouble;
	static int precision;

	static bool stateGamma;
	static double gamma;

	GetAccessorProtected(int, limit, Limit)
	GetAccessorProtected(int, result, Result)
	void SetResult(const int result);

protected:
	void RefreshResult();
};

#endif