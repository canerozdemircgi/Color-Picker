#include "CWebRest.hpp"

#include <QtCore/QEventLoop>
#include <QtNetwork/QNetworkReply>

QString CWebRest::requestGet(const QString& address, const QString& fallback, uint16_t timeout)
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