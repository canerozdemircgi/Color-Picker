#pragma once

#include <QtWidgets/QWidget>

namespace Ui { class CWindowMain; }

class CPushButtonSta;

class CWindowMain final : public QWidget
{
public:
	explicit CWindowMain(QWidget* const parent);
	~CWindowMain() override;

private:
	const Ui::CWindowMain* const ui;
	CPushButtonSta* const SimpleMode_PushButton;

	void showEvent(QShowEvent* const event) override;
	bool eventFilter(QObject* const object, QEvent* const event) override;

friend class CConfiguration;
};