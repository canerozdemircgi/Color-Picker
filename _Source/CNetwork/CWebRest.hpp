#pragma once

#include "CCore/CString.hpp"

using namespace Qt::Literals::StringLiterals;

class CWebRest final
{
public:
	template <typename CString>
	static CString requestGet(const QString& address, const CString& fallback = u""_s, uint16_t timeout = 10000u) noexcept;
};