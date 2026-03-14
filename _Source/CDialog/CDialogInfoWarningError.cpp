#include "CDialogInfoWarningError.hpp"

const CDialogInfoWarningError::Type CDialogInfoWarningError::Type::INFO =
{
	u"INFO"_s,
	QIcon(u":/Window/Info.svg"_s)
};
const CDialogInfoWarningError::Type CDialogInfoWarningError::Type::WARNING =
{
	u"WARNING"_s,
	QIcon(u":/Window/Warning.svg"_s)
};

CDialogInfoWarningError::CDialogInfoWarningError(QWidget* const parent, const CDialogInfoWarningError::Type& type, const QString& content) :
	CDialogOk(parent, {.windowType = Qt::WindowType::ToolTip, .icon = type.icon, .title = type.name}, content)
{
}