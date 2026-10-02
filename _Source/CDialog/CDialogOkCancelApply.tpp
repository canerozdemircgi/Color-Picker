#pragma once

#include "CDialogOkCancelApply.hpp"
#include "ui_CDialogOkCancelApply.h"

template <CLambda<void> Function>
void CDialogOkCancelApply::setApplyAction(Function&& function) const noexcept
{
	this->ui->Apply_PushButton->setMouseReleased(std::forward<Function>(function));
}