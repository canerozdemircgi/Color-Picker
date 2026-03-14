#pragma once

#include <cstdint>
#include <utility>

class QColor;

class CColor final
{
public:
	static float luminance(const QColor& color);

	enum class Spec : std::uint8_t { RGB, GRY, HSL, HSV };
	static QColor randomColor(CColor::Spec spec, std::pair<const uint8_t, const uint8_t> xRange, std::pair<const uint8_t, const uint8_t> yRange, std::pair<const uint8_t, const uint8_t> zRange, std::pair<const uint8_t, const uint8_t> wRange = {255, 255});
};