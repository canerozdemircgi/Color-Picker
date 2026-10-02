#include "CLabelTarget.hpp"

#include "CGui/CColor.hpp"

using namespace Qt::Literals::StringLiterals;

namespace
{

const QByteArray COLOR_DARK{"#000000"_ba};
const QByteArray COLOR_LIGHT{"#ffffff"_ba};

}

CLabelTarget::CLabelTarget(QWidget* const parent, QCache<const QString, const QPixmap>* const cachePixmap) noexcept :
	CLabelSvg{parent, {{.path = u":/Target/Cross.svg"_s}, {.cachePixmap = cachePixmap, .cacheColors = {COLOR_DARK, COLOR_LIGHT}}}}
{
}

void CLabelTarget::setColor(const QColor& color) noexcept
{
	CLabelSvg::setColor(CColor::luminance(color) > 0.5f ? COLOR_DARK : COLOR_LIGHT);
}