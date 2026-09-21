#include "CSvg.hpp"

#include "CCore/CFile.tpp"

#include <QtCore/QCache>
#include <QtCore/QCoreApplication>
#include <QtGui/QPainter>
#include <QtSvg/QSvgRenderer>

QPixmap CSvg::createPixmap(const CSvg::Parameters& parameters)
{
	static QHash<const QString, QByteArray> CACHE_FILE;
	static QCache<const QString, const QPixmap> CACHE_PIXMAP(64);

	QCache<const QString, const QPixmap>& cachePixmap = parameters.cachePixmap ? *parameters.cachePixmap : CACHE_PIXMAP;

	const QString key = QString::asprintf("%s;%d;%d;%d;%s", qUtf8Printable(*parameters.path), *parameters.width, *parameters.height, parameters.keepAspectRatio, qUtf8Printable(parameters.color));
	if (cachePixmap.contains(key))
		return *cachePixmap.object(key);

	const QByteArray content = [](const CSvg::Parameters& parameters)
	{
		if (!CACHE_FILE.contains(parameters.path))
			CACHE_FILE.insert(parameters.path, CFile::readFile<QByteArray>(parameters.path));

		if (!parameters.color.isEmpty())
			return CACHE_FILE.value(parameters.path).replace("#color#"_ba, parameters.color);
		return CACHE_FILE.value(parameters.path);
	}(parameters);

	QSvgRenderer svgRenderer(content);

	QPixmap* const pixmap = new QPixmap(parameters.width, parameters.height);
	pixmap->fill(Qt::GlobalColor::transparent);

	QPainter painter(pixmap);
	painter.setRenderHints(QPainter::RenderHint::Antialiasing | QPainter::RenderHint::SmoothPixmapTransform);

	if (parameters.keepAspectRatio)
	{
		const QSize svgSize = svgRenderer.defaultSize();
		const double svgRatio = static_cast<double>(svgSize.width()) / static_cast<double>(svgSize.height());
		const double targetRatio = static_cast<double>(parameters.width) / static_cast<double>(parameters.height);

		const auto [width, height] = [](const uint16_t width, const uint16_t height, const double svgRatio, const double targetRatio) -> std::pair<const double, const double>
		{
			if (qAbs(svgRatio - targetRatio) < 1e-8)
				return {width, height};
			if (svgRatio > targetRatio)
				return {width, width / svgRatio};
			return {height * svgRatio, height};
		}(parameters.width, parameters.height, svgRatio, targetRatio);
		const double x = (parameters.width - width) / 2.0;
		const double y = (parameters.height - height) / 2.0;

		svgRenderer.render(&painter, QRectF(x, y, width, height));
	}
	else
		svgRenderer.render(&painter, QRectF(0, 0, parameters.width, parameters.height));

	cachePixmap.insert(key, pixmap);

	if (!parameters.cacheColors.empty())
	{
		QMetaObject::invokeMethod(QCoreApplication::instance(), [](const CSvg::Parameters& parameters)
		{
			const std::span<const QByteArray> cacheColors = parameters.cacheColors;
			const QByteArray color = parameters.color;

			parameters.cacheColors = {};
			for (const QByteArray& cacheColor : cacheColors)
			{
				if (cacheColor != color)
				{
					parameters.color = cacheColor;
					CSvg::createPixmap(parameters);
				}
			}
		}, Qt::ConnectionType::QueuedConnection, parameters);
	}

	return *pixmap;
}