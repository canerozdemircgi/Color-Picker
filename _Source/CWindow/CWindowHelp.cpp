#include "CWindowHelp.hpp"

#include "CCore/CFile.tpp"

CWindowHelp::CWindowHelp(QWidget* const parent) :
	CDialogOk{parent, {.windowType = Qt::WindowType::SubWindow, .title = u"Help"_s, .dispose = false}, CFile::readFile<QString>(u":/Html/Help.html"_s).remove('\n')}
{
}

QWidget& CWindowHelp::getInstance()
{
	static CWindowHelp* const INSTANCE = new CWindowHelp(CGui::window());
	return *INSTANCE;
}