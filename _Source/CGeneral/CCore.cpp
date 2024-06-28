#include "CCore.h"

#include <QtCore/QStandardPaths>

#include <cmath>

const QString CCore::folderConfig(QStandardPaths::writableLocation(QStandardPaths::StandardLocation::DocumentsLocation) + "/Color-Picker");
const QString CCore::fileConfig(folderConfig + "/Color Picker.cfg");

const Qt::ConnectionType CCore::connection(static_cast<Qt::ConnectionType>(Qt::ConnectionType::DirectConnection | Qt::ConnectionType::UniqueConnection));

const QList<QString> CCore::SeparateQString(const QString &__restrict__ value, const QChar separator, const int count, bool *__restrict__ ok)
{
	const QList<QString> result(value.split(separator));
	*ok = result.count() == count;
	return result;
}

int CCore::RoundToInt(const double value)
{
	return static_cast<int>(value >= 0.0 ? value + 0.5 : value - 0.5);
}

int CCore::RandomInt(const int minimum, const int maximum)
{
	return RoundToInt(static_cast<double>(minimum) + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX) / static_cast<double>(maximum - minimum)));
}

int CCore::RandomPInt(const int minimum, const int maximum, const int limit)
{
	return (RandomInt(minimum, maximum) + limit) % limit;
}

int CCore::Lumina(const int x, const int y, const int z)
{
	return RoundToInt(static_cast<double>(x) * 0.2126 + static_cast<double>(y) * 0.7152 + static_cast<double>(z) * 0.0722);
}

int CCore::Interp(const int x, const int y, const int z)
{
	return RoundToInt(static_cast<double>(x + y + z) / 3.0);
}

double CCore::PowFull(const double x, const double y)
{
	return x >= 0.0 ? pow(x, y) : -1.0 * pow(-1.0 * x, y);
}