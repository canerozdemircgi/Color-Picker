#pragma once

#include "CCore/CLambda.hpp"
#include "CDialog/CDialog.hpp"

#include <QtWidgets/QWidget>

namespace Ui { class CDialogOkCancelApply; }

class CDialogOkCancelApply /*final*/ : public QWidget
{
public:
	struct ParametersExtended /*final*/
	{
		const bool buttons = false;
	};
	struct Parameters final : public CDialog::ParametersBase, CDialogOkCancelApply::ParametersExtended {};

	explicit CDialogOkCancelApply(QWidget* const parent, const CDialogOkCancelApply::Parameters& parameters, QWidget* const content = nullptr) noexcept;
	~CDialogOkCancelApply() noexcept override;

	template <CLambda::CCallable<void> Function>
	void setApplyAction(Function&& function) const noexcept;

protected:
	void setContent(QWidget* const content, bool setGeometryMinimumCenter = false) noexcept;

private:
	const Ui::CDialogOkCancelApply* const ui;
};