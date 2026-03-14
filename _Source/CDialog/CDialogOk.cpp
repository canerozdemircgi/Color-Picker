#include "CDialogOk.hpp"

#include "CGui/CGui.hpp"

#include <QtWidgets/QLabel>

CDialogOk::CDialogOk(QWidget* const parent, CDialog::ParametersBase&& parameters, const QString& content) :
	CDialogOkCancelApply(parent, {std::move(parameters)}),

	Main_Label(new QLabel)
{
	this->Main_Label->setAlignment(Qt::AlignmentFlag::AlignCenter);
	this->Main_Label->setCursor(Qt::CursorShape::IBeamCursor);
	this->Main_Label->setOpenExternalLinks(true);
	this->Main_Label->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByMouse | Qt::TextInteractionFlag::TextSelectableByMouse);
	CDialogOkCancelApply::setContent(this->Main_Label);

	if (!content.isEmpty())
		this->setContent(content, true);
}

void CDialogOk::setContent(const QString& content, bool setGeometryMinimumCenter)
{
	this->Main_Label->setText(content);

	if (setGeometryMinimumCenter)
		CGui::setGeometryMinimumCenter(this);
}