#pragma once

#include <QtWidgets/QWidget>

class CWidgetSize;

class CWidgetsSize final : private QWidget
{
public:
	explicit CWidgetsSize(QWidget* const parent);

	void setVisible(bool visible) override;

private:
	const std::array<CWidgetSize* const, 2u> instances;

	void showEvent(QShowEvent* const event) override;

	bool eventFilter(QObject* const object, QEvent* const event) override;
};