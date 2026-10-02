#pragma once

#include "CCore/CLambda.hpp"

#include <QtWidgets/QWidget>

class CWidgetMove final : public QWidget
{
public:
	explicit CWidgetMove(QWidget* const parent) noexcept;

	template <CLambda<void> Function>
	void setMouseDoubleClicked(Function&& mouseDoubleClicked) noexcept;

private:
	bool active;
	void mouseMoveEvent(QMouseEvent* const event) noexcept override;
	void mouseReleaseEvent(QMouseEvent* const event) noexcept override;

	std::move_only_function<void() const noexcept> mouseDoubleClicked;
	bool mouseDoubleClick;
	void mouseDoubleClickEvent(QMouseEvent* const event) noexcept override;
};