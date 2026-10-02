#include "CWebRest.hpp"

#include <QtCore/QEventLoop>
#include <QtNetwork/QNetworkReply>

template <typename CString>
CString CWebRest::requestGet(const QString& address, const CString& fallback, uint16_t timeout) noexcept
{
	QNetworkRequest networkRequest(address);
	networkRequest.setTransferTimeout(timeout);

	QNetworkAccessManager networkAccessManager;
	QNetworkReply* const networkReply = networkAccessManager.get(networkRequest);

	QEventLoop eventLoop;
	QObject::connect(networkReply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
	eventLoop.exec();

	if (networkReply->error() == QNetworkReply::NetworkError::NoError)
		return networkReply->readAll();
	return fallback;
}