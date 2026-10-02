#pragma once

#include "CWidgetMove.hpp"

template <CLambda<void> Function>
void CWidgetMove::setMouseDoubleClicked(Function&& mouseDoubleClicked) noexcept
{
	this->mouseDoubleClicked = std::forward<Function>(mouseDoubleClicked);
}