#pragma once

#include <utility>

namespace cstd
{

template<typename T>
class required final
{
public:
	constexpr explicit required(T&& value) : value(std::forward<T>(value)) {}

	template <typename U> requires std::constructible_from<T, U>
	constexpr /*explicit*/ required(U&& value) : value(std::forward<U>(value)) {}

	constexpr /*explicit*/ operator const T&() const { return this->value; }
	constexpr const T& operator *() const { return this->value; }

private:
	const T value;
};

}