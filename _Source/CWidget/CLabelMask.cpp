#include "CLabelMask.hpp"

using namespace Qt::Literals::StringLiterals;

namespace
{

const QString path{u":/Target/Mask.svg"_s};

}

CLabelMask::CLabelMask(QWidget* const parent, CSvg::ParametersExtended&& parameters) noexcept :
	CLabelSvg{parent, {{.path = path, .keepAspectRatio = false}, std::move(parameters)}}
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