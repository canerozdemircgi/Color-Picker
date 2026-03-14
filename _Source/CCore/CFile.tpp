#pragma once

#include "CFile.hpp"

#include "CDialog/CDialogInfoWarningError.hpp"
#include "CGui/CGui.hpp"

#include <QtCore/QCoreApplication>
#include <QtCore/QFile>

template <typename TString>
TString CFile::readFile(const QString& path, const TString& fallback)
{
	if (QFile file(path); file.open(QIODevice::OpenModeFlag::ReadOnly | QIODevice::OpenModeFlag::Text))
		return file.readAll();
	return fallback;
}

template <typename TString>
TString CFile::readResource(const QString& folderResource, const QString& fileName, const TString& fallback)
{
	for (uint8_t i = 0u; i < 2u; ++i)
	{
		if (i != 0u)
		{
			QMetaObject::invokeMethod(QCoreApplication::instance(), [](QStringView fileName)
			{
				CDialogInfoWarningError* const warningDialog = new CDialogInfoWarningError(CGui::window(), CDialogInfoWarningError::Type::WARNING, u"Failed to load file: %1\nApplication has restored the default file."_s.arg(fileName));
				warningDialog->show();
			}, Qt::ConnectionType::QueuedConnection, fileName);
		}

		if (const TString result = CFile::readFile<TString>(fileName, fallback); result != fallback)
			return result;

		QFile(u":/%1/%2"_s.arg(folderResource, fileName)).copy(u"%1/%2"_s.arg(QCoreApplication::applicationDirPath(), fileName));
		QFile::setPermissions(fileName, QFile::Permission::ReadOwner | QFile::Permission::WriteOwner | QFile::Permission::ReadUser | QFile::Permission::WriteUser | QFile::Permission::ReadGroup | QFile::Permission::WriteGroup | QFile::Permission::ReadOther);
	}

	return fallback;
}

template <typename T>
void CFile::writeFile(const QString& path, const T& content)
{
	if (QFile file(path); file.open(QIODevice::OpenModeFlag::WriteOnly/* | QIODevice::OpenModeFlag::Text*/))
		file.write(content);
}