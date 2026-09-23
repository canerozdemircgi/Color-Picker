#pragma once

#include <Qt>

class QRect;
class QWidget;

class CGui final
{
public:
	static void makeFrameless(QWidget* const widget, Qt::WindowType windowType = Qt::WindowType::Window) noexcept;

	static QWidget* window() noexcept;

	static QRect availableGeometryCurrentScreen() noexcept;
	static QRect availableGeometryAllScreens() noexcept;

	static void setGeometryMinimumCenter(QWidget* const widget) noexcept;

private:
	static void invalidateLayout(const QWidget* const widget) noexcept;
};