#include "CLabelSvg.hpp"

CLabelSvg::CLabelSvg(QWidget* const parent, CSvg::ParametersBase&& parameters) noexcept :
	QLabel{parent},

	parameters{std::move(parameters)}
{
	this->setProperty("hasNoBackground", true);
}

void CLabelSvg::setColor(QByteArray color) const noexcept
{
	parameters.color = std::move(color);
}

void CLabelSvg::refreshPixmap() noexcept
{
	if (this->isVisible())
		this->setPixmap(CSvg::createPixmap({this->parameters, {.width = this->width(), .height = this->height()}}));
}

void CLabelSvg::showEvent(QShowEvent* const event) noexcept
{
	this->refreshPixmap();

	QLabel::showEvent(event);
}

void CLabelSvg::resizeEvent(QResizeEvent* const event) noexcept
{
	this->refreshPixmap();

	QLabel::resizeEvent(event);
}