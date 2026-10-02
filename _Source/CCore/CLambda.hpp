#pragma once

#include <concepts>

template <typename F, typename R, typename... Args>
concept CLambda = std::invocable<F, Args...> && std::same_as<std::invoke_result_t<F, Args...>, R>;