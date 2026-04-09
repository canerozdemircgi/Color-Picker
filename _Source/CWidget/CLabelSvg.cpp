#include "CLabelSvg.hpp"

CLabelSvg::CLabelSvg(QWidget* const parent, CSvg::ParametersBase&& parameters) :
	QLabel{parent},

	parameters{std::move(parameters)}
{
	this->setProperty("hasNoBackground", true);
}

void CLabelSvg::setColor(QByteArray color)
{
	parameters.color = std::move(color);
}

void CLabelSvg::refreshPixmap()
{
	if (this->isVisible())
		this->setPixmap(CSvg::createPixmap({this->parameters, {.width = this->width(), .height = this->height()}}));
}

void CLabelSvg::showEvent(QShowEvent* const event)
{
	this->refreshPixmap();

	QLabel::showEvent(event);
}

void CLabelSvg::resizeEvent(QResizeEvent* const event)
{
	this->refreshPixmap();

	QLabel::resizeEvent(event);
}