#pragma once

#include <QtWidgets/QProxyStyle>

class CProxyStyle final : public QProxyStyle
{
public:
	explicit CProxyStyle() noexcept;

private:
	int pixelMetric(QStyle::PixelMetric pixelMetric, const QStyleOption* const styleOption, const QWidget* const widget) const noexcept override;
	QPixmap generatedIconPixmap(QIcon::Mode mode, const QPixmap& pixmap, const QStyleOption* const styleOption) const noexcept override;
};