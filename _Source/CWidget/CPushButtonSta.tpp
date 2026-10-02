#pragma once

#include "CPushButtonSta.hpp"

template <CLambda<void> Function>
void CPushButtonSta::setMouseReleased(Function&& mouseReleased) noexcept
{
	this->mouseReleased = std::forward<Function>(mouseReleased);
}

template <CLambda<void> Function>
void CPushButtonSta::setMouseLeftReleased(Function&& mouseLeftReleased) noexcept
{
	this->mouseLeftReleased = std::forward<Function>(mouseLeftReleased);
}

template <CLambda<void> Function>
void CPushButtonSta::setMouseRightReleased(Function&& mouseRightReleased) noexcept
{
	this->mouseRightReleased = std::forward<Function>(mouseRightReleased);
}

template <CLambda<void> Function>
void CPushButtonSta::setMouseMiddleReleased(Function&& mouseMiddleReleased) noexcept
{
	this->mouseMiddleReleased = std::forward<Function>(mouseMiddleReleased);
}