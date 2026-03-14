#pragma once

#include <QtCore/QString>

template <typename T>
concept TString = std::same_as<T, QString> || std::same_as<T, QByteArray>;

class CFile final
{
public:
	template <typename TString>
	static TString readFile(const QString& path, const TString& fallback = nullptr);

	template <typename TString>
	static TString readResource(const QString& folderResource, const QString& fileName, const TString& fallback = nullptr);

	template <typename T>
	static void writeFile(const QString& path, const T& content);
};