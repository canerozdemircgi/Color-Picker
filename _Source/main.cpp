#include "CConfiguration/CConfiguration.hpp"
#include "CGui/CStyle.hpp"
#include "CSystem/CPlatform.hpp"
#include "CWindow/CWindowMain.hpp"

#include <QtWidgets/QApplication>

int main(int argc, char** const argv)
{
	CPlatform::setProcessPriority(CPlatform::Priority::HIGH);

	QApplication application{argc, argv};
	CStyle::initialize(&application);

	CWindowMain mainWindow{nullptr};
	CConfiguration::initialize(&mainWindow);

	#ifdef _WIN32
	CPlatform::fixResize();
	#endif

	mainWindow.show();
	return QApplication::exec();
}