#pragma once

#include "CCore/CLambda.hpp"

#include <QtWidgets/QWidget>

class CWidgetMove final : public QWidget
{
public:
	explicit CWidgetMove(QWidget* const parent);

	template <CLambda::CCallable<void> Function>
	void setMouseDoubleClicked(Function&& mouseDoubleClicked);

private:
	bool active;
	void mouseMoveEvent(QMouseEvent* const event) override;
	void mouseReleaseEvent(QMouseEvent* const event) override;

	std::move_only_function<void()> mouseDoubleClicked;
	void mouseDoubleClickEvent(QMouseEvent* const event) override;
};