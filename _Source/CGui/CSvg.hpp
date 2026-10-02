#pragma once

#include "CCore/CStandart.hpp"

#include <QtCore/QSize>

#include <vector>

class QPixmap;

template <typename Key, typename Value>
class QCache;

class CSvg final
{
public:
	struct ParametersBasic /*final*/
	{
		const cstd::required<const QString> path;

		const bool keepAspectRatio = true;
	};
	struct ParametersExtended /*final*/
	{
		QByteArray color;

		QCache<const QString, const QPixmap>* const cachePixmap = nullptr;
		std::vector<QByteArray> cacheColors;
	};
	struct ParametersBase /*final*/ : public CSvg::ParametersBasic, public CSvg::ParametersExtended {};

	struct ParametersSize /*final*/
	{
		const cstd::required<const uint16_t> width;
		const cstd::required<const uint16_t> height;
	};
	struct Parameters final : public CSvg::ParametersBase, public CSvg::ParametersSize {};

	static QPixmap createPixmap(const CSvg::Parameters& parameters) noexcept;
};