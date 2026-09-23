#pragma once

#include "CWidgetMove.hpp"

template <CLambda::CCallable<void> Function>
void CWidgetMove::setMouseDoubleClicked(Function&& mouseDoubleClicked) noexcept
{
	this->mouseDoubleClicked = std::move(mouseDoubleClicked);
}