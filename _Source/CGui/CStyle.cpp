#include "CStyle.hpp"

#include "CCore/CFile.tpp"
#include "CGui/CProxyStyle.hpp"

#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>

void CStyle::initialize(QApplication* const application)
{
	Q_ASSERT(QFontDatabase::addApplicationFont(u":/Font/Roboto-VariableFont_wdth,wght.ttf"_s) != -1);
	QFont font(u"Roboto"_s);
	font.setPointSize(9);
	font.setKerning(true);
	font.setHintingPreference(QFont::HintingPreference::PreferVerticalHinting);
	font.setStyleStrategy(static_cast<QFont::StyleStrategy>(QFont::StyleStrategy::ForceOutline | QFont::StyleStrategy::PreferMatch));
	font.setLetterSpacing(QFont::SpacingType::AbsoluteSpacing, 0.25);
	QApplication::setFont(font);

	QApplication::setStyle(new CProxyStyle);

	application->setStyleSheet(CFile::readResource<QString>(u"Style"_s, u"ColorPicker.qss"_s));

	QIcon::setThemeSearchPaths({u":/Icon"_s});
	QIcon::setThemeName(u"Theme"_s);
}