#pragma once

#include "CCore/CLambda.hpp"

#include <QtCore/QEvent>
#include <QtWidgets/QPushButton>

class CPushButtonSta final : public QPushButton
{
public:
	explicit CPushButtonSta(QWidget* const parent) noexcept;

	void mousePressAndRelease() noexcept;
	void setChecked(bool checked) noexcept;

	template <CLambda::CCallable<void> Function>
	void setMouseReleased(Function&& mouseReleased) noexcept;
	template <CLambda::CCallable<void> Function>
	void setMouseLeftReleased(Function&& mouseLeftReleased) noexcept;
	template <CLambda::CCallable<void> Function>
	void setMouseRightReleased(Function&& mouseRightReleased) noexcept;
	template <CLambda::CCallable<void> Function>
	void setMouseMiddleReleased(Function&& mouseMiddleReleased) noexcept;

private:
	std::move_only_function<void() noexcept> mouseReleased;
	std::move_only_function<void() noexcept> mouseLeftReleased;
	std::move_only_function<void() noexcept> mouseRightReleased;
	std::move_only_function<void() noexcept> mouseMiddleReleased;

	static QMouseEvent redirectMouseEvent(const QMouseEvent& event) noexcept;
	static QMouseEvent redirectMouseEvent(const QMouseEvent& event, QEvent::Type type) noexcept;

	void mousePressEvent(QMouseEvent* const event) noexcept override;
	void mouseReleaseEvent(QMouseEvent* const event) noexcept override;

	void keyPressEvent(QKeyEvent* const event) noexcept override;
};