#include "CMainWindow.h"

#include "CGeneral/CStyle.h"

#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStyleFactory>

int main(int argc, char *argv[])
{
	QFontDatabase::addApplicationFont(":/Font/Roboto-Regular");
	QFont font("Roboto");
	font.setPointSizeF(8.6);

	const QApplication application(argc, argv);
	application.setStyle(QStyleFactory::create(CStyle::style));
	application.setFont(font);

	CMainWindow windowMain;
	windowMain.show();

	return application.exec();
}