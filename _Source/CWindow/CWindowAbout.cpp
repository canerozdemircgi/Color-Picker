#include "CWindowAbout.hpp"

#include "CCore/CApplication.hpp"
#include "CCore/CFile.tpp"
#include "CNetwork/CWebRest.hpp"

#include <opencv2/core/version.hpp>

CWindowAbout::CWindowAbout(QWidget* const parent) :
	CDialogOk(parent, {.windowType = Qt::WindowType::SubWindow, .title = u"About"_s, .dispose = false})
{
	const QString versionBlank(u"x.x.x"_s);

	const QString content = CFile::readFile<QString>(u":/Html/About.html"_s).remove('\n');
	this->setContent(content.arg(versionBlank, versionBlank, versionBlank, versionBlank), true);

	QMetaObject::invokeMethod(this, [this](const QString& content, const QString& versionBlank)
	{
		const QStringView versionQt = QStringLiteral(QT_VERSION_STR);
		const QStringView versionOpenCv = QStringLiteral(CV_VERSION);
		const QString versionLocal = CFile::readFile<QString>(u":/Other/version.txt"_s);

		this->setContent(content.arg(versionQt, versionOpenCv, versionLocal, versionBlank));
		CApplication::processEvents();

		const QString versionRemote = CWebRest::requestGet(u"https://raw.githubusercontent.com/canerozdemircgi/Color-Picker/refs/heads/main/version.txt"_s, versionBlank);
		this->setContent(content.arg(versionQt, versionOpenCv, versionLocal, versionRemote));
	}, Qt::ConnectionType::QueuedConnection, content, versionBlank);
}

QWidget& CWindowAbout::getInstance()
{
	static CWindowAbout* const INSTANCE = new CWindowAbout(CGui::window());
	return *INSTANCE;
}