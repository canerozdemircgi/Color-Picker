#include "CLabelMask.hpp"

using namespace Qt::Literals::StringLiterals;

CLabelMask::CLabelMask(QWidget* const parent, CSvg::ParametersExtended&& parameters) noexcept :
	CLabelSvg{parent, {{.path = u":/Target/Mask.svg"_s, .keepAspectRatio = false}, std::forward<CSvg::ParametersExtended>(parameters)}}
{
}

void CLabelMask::enterEvent(QEnterEvent* const event) noexcept
{
	this->pixmapOriginal = std::move(this->pixmap());
	this->setPixmap({});

	CLabelSvg::enterEvent(event);
}

void CLabelMask::leaveEvent(QEvent* const event) noexcept
{
	this->setPixmap(this->pixmapOriginal);

	CLabelSvg::leaveEvent(event);
}