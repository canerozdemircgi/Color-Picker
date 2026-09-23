#pragma once

#include "CDialogOkCancelApply.hpp"
#include "ui_CDialogOkCancelApply.h"

template <CLambda::CCallable<void> Function>
void CDialogOkCancelApply::setApplyAction(Function&& function) const noexcept
{
	this->ui->Apply_PushButton->setMouseReleased(std::move(function));
}