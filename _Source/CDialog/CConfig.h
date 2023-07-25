#ifndef CConfig_H
#define CConfig_H

#include "../CButton/CPushButton_Sta.h"
#include "../CLabel/CLabel_Title.h"

#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

class CConfig : public QDialog
{
	Q_OBJECT

public:
	explicit CConfig(const QWidget *__restrict__ parent, const std::function<void(const int)> &__restrict__ State_FloatPrec_QSpinBox_valueChanged);

	static int startSlots;
	static QString colorEmpty;
	static QString colorCustom;

private:
	CLabel_Title Title_QLabel;

	QLabel Icon_QLabel;
	CPushButton_Sta Close_QPushButton;

	QLabel StartSlots_QLabel;
	QComboBox StartSlots_QComboBox;
	QLineEdit CustomSlot_QLineEdit;
	CPushButton_Sta CustomSlot_QPushButton;

	QLabel EmptyColor_QLabel;
	QLineEdit EmptyColor_QLineEdit;
	QLabel FloatPrec_QLabel;
	QSpinBox FloatPrec_QSpinBox;

	QFrame QLineBorder_5;

	void State_CustomSlot_QPushButton_MouseLeftReleased();

	const std::function<void(const int)> State_FloatPrec_QSpinBox_valueChanged;

private slots:
	void State_StartSlots_QComboBox_currentIndexChanged(const int index);
	static void State_CustomSlot_QLineEdit_textEdited(const QString &__restrict__ arg);
	void State_EmptyColor_QLineEdit_returnPressed() const;

public:
	enum Slots
	{
		Random,
		Empty,
		Custom
	};
};

#endif