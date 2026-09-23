#pragma once

#include "CWidget/CLabelSvg.hpp"

class CLabelTarget final : public CLabelSvg
{
public:
	explicit CLabelTarget(QWidget* const parent, QCache<const QString, const QPixmap>* const cachePixmap = nullptr) noexcept;

	void setVisible(bool visible) noexcept override;
};