#pragma once

#include "CCore/CString.hpp"

class CFile final
{
public:
	template <typename CString>
	static CString readFile(const QString& path, const CString& fallback = nullptr) noexcept;

	template <typename CString>
	static CString readResource(const QString& folderResource, const QString& fileName, const CString& fallback = nullptr) noexcept;

	template <typename T>
	static void writeFile(const QString& path, const T& content) noexcept;
};