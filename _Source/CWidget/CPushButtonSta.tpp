#pragma once

#include "CPushButtonSta.hpp"

template <CLambda::CCallable<void> Function>
void CPushButtonSta::setMouseReleased(Function&& mouseReleased)
{
	this->mouseReleased = std::move(mouseReleased);
}

template <CLambda::CCallable<void> Function>
void CPushButtonSta::setMouseLeftReleased(Function&& mouseLeftReleased)
{
	this->mouseLeftReleased = std::move(mouseLeftReleased);
}

template <CLambda::CCallable<void> Function>
void CPushButtonSta::setMouseRightReleased(Function&& mouseRightReleased)
{
	this->mouseRightReleased = std::move(mouseRightReleased);
}

template <CLambda::CCallable<void> Function>
void CPushButtonSta::setMouseMiddleReleased(Function&& mouseMiddleReleased)
{
	this->mouseMiddleReleased = std::move(mouseMiddleReleased);
}