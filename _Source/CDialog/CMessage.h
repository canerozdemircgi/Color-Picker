#ifndef CMessage_H
#define CMessage_H

#include "../CButton/CPushButton_Sta.h"
#include "../CLabel/CLabel_Title.h"

#include <QtWidgets/QDialog>

class CMessage : public QDialog
{
public:
	explicit CMessage(const QWidget *__restrict__ parent, const QString &__restrict__ title, const QString &__restrict__ message);

private:
	CLabel_Title Title_QLabel;

	QLabel Icon_QLabel;
	CPushButton_Sta Close_QPushButton;

	QLabel Message_QLabel;

	QFrame QLineBorder_5;
};

#endif