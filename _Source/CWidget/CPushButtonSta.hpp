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

	template <CLambda<void> Function>
	void setMouseReleased(Function&& mouseReleased) noexcept;
	template <CLambda<void> Function>
	void setMouseLeftReleased(Function&& mouseLeftReleased) noexcept;
	template <CLambda<void> Function>
	void setMouseRightReleased(Function&& mouseRightReleased) noexcept;
	template <CLambda<void> Function>
	void setMouseMiddleReleased(Function&& mouseMiddleReleased) noexcept;

private:
	static QMouseEvent redirectMouseLeftEvent(const QMouseEvent& event) noexcept;
	static QMouseEvent redirectMouseLeftEvent(const QMouseEvent& event, QEvent::Type type) noexcept;

	std::move_only_function<void() const noexcept> mouseReleased;
	std::move_only_function<void() const noexcept> mouseLeftReleased;
	std::move_only_function<void() const noexcept> mouseRightReleased;
	std::move_only_function<void() const noexcept> mouseMiddleReleased;

	void mousePressEvent(QMouseEvent* const event) noexcept override;
	void mouseReleaseEvent(QMouseEvent* const event) noexcept override;

	void keyPressEvent(QKeyEvent* const event) noexcept override;
};