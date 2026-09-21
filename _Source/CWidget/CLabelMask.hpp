#pragma once

#include "CWidget/CLabelSvg.hpp"

class CLabelMask final : public CLabelSvg
{
public:
	explicit CLabelMask(QWidget* const parent, CSvg::ParametersExtended&& parameters);

private:
	QPixmap pixmapOriginal;

	void enterEvent(QEnterEvent* const event) override;
	void leaveEvent(QEvent* const event) override;
};