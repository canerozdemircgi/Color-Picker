#include "CProxyStyle.hpp"

#include <QtGui/QPainter>

using namespace Qt::Literals::StringLiterals;

CProxyStyle::CProxyStyle() :
	QProxyStyle(u"Fusion"_s)
{
}

int CProxyStyle::pixelMetric(QStyle::PixelMetric pixelMetric, const QStyleOption* const styleOption, const QWidget* const widget) const
{
	if (pixelMetric == QStyle::PixelMetric::PM_SmallIconSize)
		return 12;

	return QProxyStyle::pixelMetric(pixelMetric, styleOption, widget);
}

QPixmap CProxyStyle::generatedIconPixmap(QIcon::Mode mode, const QPixmap& pixmap, const QStyleOption* const styleOption) const
{
	static constexpr QColor DISABLED_COLOR(0, 0, 0, 128);

	if (mode == QIcon::Mode::Disabled)
	{
		if (pixmap.isNull())
			return pixmap;

		QPixmap pixmapCopy(pixmap);
		QPainter painter(&pixmapCopy);
		painter.setCompositionMode(QPainter::CompositionMode::CompositionMode_DestinationIn);
		painter.fillRect(pixmapCopy.rect(), DISABLED_COLOR);
		return pixmapCopy;
	}

	return QProxyStyle::generatedIconPixmap(mode, pixmap, styleOption);
}