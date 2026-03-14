#include "CDialogOkCancelApply.hpp"
#include "ui_CDialogOkCancelApply.h"

#include "CGui/CGui.hpp"
#include "CGui/CUi.hpp"
#include "CWidget/CPushButtonSta.tpp"

#include <QtGui/QWindow>

CDialogOkCancelApply::CDialogOkCancelApply(QWidget* const parent, const CDialogOkCancelApply::Parameters& parameters, QWidget* const content) :
	QWidget(parent),

	ui(CUi::newUi<Ui::CDialogOkCancelApply>(this, {.windowType = parameters.windowType, .icon = parameters.icon, .title = parameters.title, .minimize = false, .dispose = parameters.dispose}))
{
	if (!parameters.buttons)
		this->ui->Bottom_Widget->setVisible(false);

	if (content)
		this->setContent(content, true);

	this->ui->Ok_PushButton->setMouseReleased([this]
	{
		this->ui->Apply_PushButton->mousePressAndRelease();
		this->ui->Cancel_PushButton->mousePressAndRelease();
	});
	this->ui->Cancel_PushButton->setMouseReleased([this]
	{
		this->window()->windowHandle()->close();
	});
}

CDialogOkCancelApply::~CDialogOkCancelApply()
{
	delete this->ui;
}

void CDialogOkCancelApply::setContent(QWidget* const content, bool setGeometryMinimumCenter)
{
	if (const QWidget* const child = this->ui->Body_Widget->findChild<const QWidget* const>(Qt::FindChildOption::FindDirectChildrenOnly))
		delete child;
	this->ui->Body_Widget->layout()->addWidget(content);

	if (setGeometryMinimumCenter)
		CGui::setGeometryMinimumCenter(this);
}