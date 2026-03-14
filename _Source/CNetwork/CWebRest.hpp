#pragma once

#include <QtCore/QString>

using namespace Qt::Literals::StringLiterals;

class CWebRest final
{
public:
	static QString requestGet(const QString& address, const QString& fallback = u""_s, uint16_t timeout = 10000u);
};