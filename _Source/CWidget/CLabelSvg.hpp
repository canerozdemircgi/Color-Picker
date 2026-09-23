#pragma once

#include "CGui/CSvg.hpp"

#include <QtWidgets/QLabel>

class CLabelSvg /*final*/ : public QLabel
{
public:
	explicit CLabelSvg(QWidget* const parent, CSvg::ParametersBase&& parameters) noexcept;

protected:
	void setColor(QByteArray color) const noexcept;

	void resizeEvent(QResizeEvent* const event) noexcept override;

private:
	const CSvg::ParametersBase parameters;

	void refreshPixmap() noexcept;

	void showEvent(QShowEvent* const event) noexcept override;
};