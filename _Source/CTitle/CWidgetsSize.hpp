#pragma once

#include <QtWidgets/QWidget>

class CWidgetSize;

class CWidgetsSize final : private QWidget
{
public:
	explicit CWidgetsSize(QWidget* const parent) noexcept;

	void setVisible(bool visible) noexcept override;

private:
	const std::array<CWidgetSize* const, 8u> instances;

	void showEvent(QShowEvent* const event) noexcept override;

	bool eventFilter(QObject* const object, QEvent* const event) noexcept override;
};