//
#include "CLabelSvg.hpp"

CLabelSvg::CLabelSvg(QWidget* const parent, CSvg::ParametersBase&& parameters) noexcept :
	QLabel{parent},

	parameters{std::forward<CSvg::ParametersBase>(parameters)}
{
	this->setProperty("hasNoBackground", true);
}

void CLabelSvg::setColor(QByteArray color) noexcept
{
	parameters.color = std::move(color);

	if (this->isVisible())
		this->refreshPixmap();
}

void CLabelSvg::refreshPixmap() noexcept
{
	this->setPixmap(CSvg::createPixmap({this->parameters, {.width = this->width(), .height = this->height()}}));
}

void CLabelSvg::showEvent(QShowEvent* const event) noexcept
{
	this->refreshPixmap();

	QLabel::showEvent(event);
}

void CLabelSvg::resizeEvent(QResizeEvent* const event) noexcept
{
	if (this->isVisible())
		this->refreshPixmap();

	QLabel::resizeEvent(event);
}