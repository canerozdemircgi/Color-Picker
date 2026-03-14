#pragma once

#include "CCore/CStandart.hpp"

#include <QtCore/QSize>

#include <span>

class QPixmap;

template <typename Key, typename Value>
class QCache;

class CSvg final
{
public:
	struct ParametersBasic /*final*/
	{
		const cstd::required<const QString&> path;

		const bool keepAspectRatio = true;
	};
	struct ParametersExtended /*final*/
	{
		mutable QByteArray color;

		QCache<const QString, QPixmap>* const cachePixmap = nullptr;
		mutable std::span<const QByteArray> cacheColors;
	};
	struct ParametersBase /*final*/ : public CSvg::ParametersBasic, CSvg::ParametersExtended {};

	struct ParametersSize /*final*/
	{
		const cstd::required<const uint16_t> width;
		const cstd::required<const uint16_t> height;
	};
	struct Parameters final : public CSvg::ParametersBase, CSvg::ParametersSize {};

	static QPixmap createPixmap(const CSvg::Parameters& parameters);
};