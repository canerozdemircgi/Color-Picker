#include "CMainWindow.h"

#include "CGeneral/CStyle.h"

#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStyleFactory>

QFont font("Roboto");

int main(int argc, char *argv[])
{
	QFontDatabase::addApplicationFont(":/Font/Roboto[wdth,wght]");
	font.setPointSizeF(8.6);
    font.setKerning(true);

	const QApplication application(argc, argv);
	application.setStyle(QStyleFactory::create(CStyle::style));
	application.setFont(font);

	CMainWindow windowMain;
	windowMain.show();

	return application.exec();
}