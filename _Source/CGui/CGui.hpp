#pragma once

#include <Qt>

class QRect;
class QWidget;

class CGui final
{
public:
	static void makeFrameless(QWidget* const widget, Qt::WindowType windowType = Qt::WindowType::Window);

	static QWidget* window();

	static QRect availableGeometryCurrentScreen();
	static QRect availableGeometryAllScreens();

	static void setGeometryMinimumCenter(QWidget* const widget);

private:
	static void invalidateLayout(const QWidget* const widget);
};