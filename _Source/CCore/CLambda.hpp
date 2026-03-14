#pragma once

#include <concepts>

namespace CLambda
{
	template <typename F, typename R, typename... Args>
	concept CCallable = std::invocable<F, Args...> && std::same_as<std::invoke_result_t<F, Args...>, R>;
}