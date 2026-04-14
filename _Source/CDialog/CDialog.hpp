#pragma once

#include "CCore/CStandart.hpp"

#include <QtGui/QIcon>

#include <boost/optional.hpp>

class CDialog final
{
public:
	struct ParametersBase /*final*/
	{
		const cstd::required<const Qt::WindowType> windowType;
		const boost::optional<const QIcon&> icon;

		const cstd::required<const QString&> title;

		const bool dispose = true;
	};
};