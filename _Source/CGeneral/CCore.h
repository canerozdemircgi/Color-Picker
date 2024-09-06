#ifndef CCore_H
#define CCore_H

#include <random>

#include <QtCore/QDebug>
#include <QtCore/QList>

class CCore
{
public:
	static const QString folderConfig;
	static const QString fileConfig;

	static const Qt::ConnectionType connection;

	static std::unique_ptr<const QList<QString>> SeparateQString(const QString &__restrict__ value, const QChar separator, const int count, bool *__restrict__ ok);

	static const int RoundToInt(const double value);
	static const int RandomInt(const int minimum, const int maximum);
	static const int RandomPInt(const int minimum, const int maximum, const int limit);

	static const int Lumina(const int x, const int y, const int z);
	static const int Interp(const int x, const int y, const int z);

	static const double PowFull(const double x, const double y);

private:
	static std::random_device rd;
	static std::mt19937 gen;
};

#endif