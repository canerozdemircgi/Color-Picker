#pragma once

#include <QtWidgets/QWidget>

namespace Ui { class CWindowMain; }

class CPushButtonSta;

class CWindowMain final : public QWidget
{
public:
	explicit CWindowMain(QWidget* const parent) noexcept;
	~CWindowMain() noexcept override;

private:
	const Ui::CWindowMain* const ui;
	CPushButtonSta& SimpleMode_PushButton;

	void changeEvent(QEvent* const event) noexcept override;

friend class CConfiguration;
};