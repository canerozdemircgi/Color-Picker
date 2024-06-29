#ifndef CCore_H
#define CCore_H

#include <iostream>
#include <QtCore/QDebug>

#include <QtCore/QList>

class CCore
{
public:
	static const QString folderConfig;
	static const QString fileConfig;

	static const Qt::ConnectionType connection;

	static const QList<QString> SeparateQString(const QString &__restrict__ value, const QChar separator, const int count, bool *__restrict__ ok);

	static int RoundToInt(const double value);
	static int RandomInt(const int minimum, const int maximum);
	static int RandomPInt(const int minimum, const int maximum, const int limit);

	static int Lumina(const int x, const int y, const int z);
	static int Interp(const int x, const int y, const int z);

	static double PowFull(const double x, const double y);
};

#endif