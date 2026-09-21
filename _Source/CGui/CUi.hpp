#pragma once

namespace CUi
{

template<typename T>
constexpr const T* newUi(QWidget* const widget)
{
	T* const ui = new T;
	ui->setupUi(widget);
	return ui;
}

template<typename T>
constexpr const T* newUi(QWidget* const widget, const CTitleBar::Parameters& parameters)
{
	const T* const ui = newUi<T>(widget);
	ui->TitleBar->initialize(parameters);
	return ui;
}

}