#include "CMainWindow.h"

#include "CGeneral/CStyle.h"

#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStyleFactory>

#include <iostream>

std::unique_ptr<const QFont> getFont()
{
	QFont font("Roboto");
	font.setPointSizeF(8.6);
	font.setKerning(true);
	return std::make_unique<const QFont>(font);
}

QFont font(*getFont());

int main(int argc, char *argv[])
{
	const QApplication application(argc, argv);

	QFontDatabase::addApplicationFont(":/Font/Roboto[wdth,wght]");

	QApplication::setStyle(QStyleFactory::create(CStyle::style));
	QApplication::setFont(font);

	CMainWindow windowMain;
	windowMain.show();

	return QApplication::exec();
}