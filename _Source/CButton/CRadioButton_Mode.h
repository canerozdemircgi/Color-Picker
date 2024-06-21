#ifndef CRadioButton_Mode_H
#define CRadioButton_Mode_H

#include <QtWidgets/QRadioButton>

#include <functional>

class CRadioButton_Mode : public QRadioButton
{
public:
	explicit CRadioButton_Mode(const int index, QWidget *__restrict__ parent);

	const int index;
	static int indexSelected;

	void checkStateSet() override;
	void nextCheckState() override;

	std::function<void()> Toggled;
};

#endif