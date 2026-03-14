#pragma once

#include "CCore/CLambda.hpp"

#include <QtCore/QEvent>
#include <QtWidgets/QPushButton>

class CPushButtonSta final : public QPushButton
{
public:
	explicit CPushButtonSta(QWidget* const parent);

	void mousePressAndRelease();
	void setChecked(bool checked);

	template <CLambda::CCallable<void> Function>
	void setMouseReleased(Function&& mouseReleased);
	template <CLambda::CCallable<void> Function>
	void setMouseLeftReleased(Function&& mouseLeftReleased);
	template <CLambda::CCallable<void> Function>
	void setMouseRightReleased(Function&& mouseRightReleased);
	template <CLambda::CCallable<void> Function>
	void setMouseMiddleReleased(Function&& mouseMiddleReleased);

private:
	std::move_only_function<void()> mouseReleased;
	std::move_only_function<void()> mouseLeftReleased;
	std::move_only_function<void()> mouseRightReleased;
	std::move_only_function<void()> mouseMiddleReleased;

	static QMouseEvent redirectMouseEvent(const QMouseEvent& event);
	static QMouseEvent redirectMouseEvent(const QMouseEvent& event, QEvent::Type type);

	void mousePressEvent(QMouseEvent* const event) override;
	void mouseReleaseEvent(QMouseEvent* const event) override;

	void keyPressEvent(QKeyEvent* const event) override;
};