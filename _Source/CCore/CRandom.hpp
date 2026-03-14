#pragma once

class CRandom final
{
public:
	template <std::integral T>
	static T generateRandomInt(T min, T max);
};