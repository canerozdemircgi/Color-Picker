#pragma once

#include "CDialog/CDialogOkCancelApply.hpp"

using namespace Qt::Literals::StringLiterals;

class QLabel;

class CDialogOk /*final*/ : protected CDialogOkCancelApply
{
public:
	explicit CDialogOk(QWidget* const parent, CDialog::ParametersBase&& parameters, const QString& content = u""_s);

protected:
	void setContent(const QString& content, bool setGeometryMinimumCenter = false);

private:
	QLabel* const Main_Label;
};