#pragma once

#include "CRandom.hpp"

#include <random>

template <std::integral T>
T CRandom::generateRandomInt(T min, T max)
{
	if (min == max)
		return min;

	static std::mt19937 GENERATOR(std::random_device{}());

	return std::uniform_int_distribution<T>(min, max)(GENERATOR);
}