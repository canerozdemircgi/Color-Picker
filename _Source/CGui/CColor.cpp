#include "CColor.hpp"

#include "CCore/CRandom.tpp"

#include <QtGui/QColor>

float CColor::luminance(const QColor& color)
{
	return color.redF() * 0.2126f + color.greenF() * 0.7152f + color.blueF() * 0.0722f;
}

QColor CColor::randomColor(CColor::Spec spec, std::pair<const uint8_t, const uint8_t> xRange, std::pair<const uint8_t, const uint8_t> yRange, std::pair<const uint8_t, const uint8_t> zRange, std::pair<const uint8_t, const uint8_t> wRange)
{
	const uint8_t x = CRandom::generateRandomInt(xRange.first, xRange.second);
	const uint8_t w = CRandom::generateRandomInt(wRange.first, wRange.second);
	if (spec == CColor::Spec::GRY)
		return QColor::fromRgb(x, x, x, w);

	const uint8_t y = CRandom::generateRandomInt(yRange.first, yRange.second);
	const uint8_t z = CRandom::generateRandomInt(zRange.first, zRange.second);
	switch (spec)
	{
		case CColor::Spec::RGB:
			return QColor::fromRgb(x, y, z, w);
		case CColor::Spec::HSL:
			return QColor::fromHsl(x, y, z, w);
		case CColor::Spec::HSV:
			return QColor::fromHsv(x, y, z, w);
		default:
			return Qt::GlobalColor::black;
	}
}