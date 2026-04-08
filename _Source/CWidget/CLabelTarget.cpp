#include "CLabelTarget.hpp"

#include "CGui/CColor.hpp"

using namespace Qt::Literals::StringLiterals;

namespace
{

const QString path{u":/Target/Cross.svg"_s};

const QByteArray COLOR_DARK{"#000000"_ba};
const QByteArray COLOR_LIGHT{"#ffffff"_ba};

const std::array<const QByteArray, 2> COLORS{COLOR_DARK, COLOR_LIGHT};

}

CLabelTarget::CLabelTarget(QWidget* const parent, QCache<const QString, const QPixmap>* const cachePixmap) :
	CLabelSvg{parent, {{.path = path}, {.cachePixmap = cachePixmap, .cacheColors = COLORS}}}
{
}

void CLabelTarget::setVisible(bool visible)
{
	if (visible)
		this->setColor(CColor::luminance(this->parentWidget()->palette().color(QPalette::ColorRole::Button)) > 0.5f ? COLOR_DARK : COLOR_LIGHT);
	CLabelSvg::setVisible(visible);
}