#pragma once

#include "CWidgetMove.hpp"

template <CLambda::CCallable<void> Function>
void CWidgetMove::setMouseDoubleClicked(Function&& mouseDoubleClicked)
{
	this->mouseDoubleClicked = std::move(mouseDoubleClicked);
}