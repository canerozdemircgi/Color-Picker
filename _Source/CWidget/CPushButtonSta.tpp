#pragma once

#include "CPushButtonSta.hpp"

template <CLambda::CCallable<void> Function>
void CPushButtonSta::setMouseReleased(Function&& mouseReleased) noexcept
{
	this->mouseReleased = std::move(mouseReleased);
}

template <CLambda::CCallable<void> Function>
void CPushButtonSta::setMouseLeftReleased(Function&& mouseLeftReleased) noexcept
{
	this->mouseLeftReleased = std::move(mouseLeftReleased);
}

template <CLambda::CCallable<void> Function>
void CPushButtonSta::setMouseRightReleased(Function&& mouseRightReleased) noexcept
{
	this->mouseRightReleased = std::move(mouseRightReleased);
}

template <CLambda::CCallable<void> Function>
void CPushButtonSta::setMouseMiddleReleased(Function&& mouseMiddleReleased) noexcept
{
	this->mouseMiddleReleased = std::move(mouseMiddleReleased);
}