#pragma once

#include "CGui/CSvg.hpp"

#include <QtWidgets/QLabel>

class CLabelSvg /*final*/ : public QLabel
{
public:
	explicit CLabelSvg(QWidget* const parent, CSvg::ParametersBase&& parameters);

protected:
	void setColor(QByteArray color) const;

	void resizeEvent(QResizeEvent* const event) override;

private:
	const CSvg::ParametersBase parameters;

	void refreshPixmap();

	void showEvent(QShowEvent* const event) override;
};