#pragma once

#include "CGui/CSvg.hpp"

#include <QtWidgets/QLabel>

class CLabelSvg /*final*/ : public QLabel
{
public:
	explicit CLabelSvg(QWidget* const parent, CSvg::ParametersBase&& parameters);

	void setColor(QByteArray color);

protected:
	void resizeEvent(QResizeEvent* const event) override;

private:
	CSvg::ParametersBase parameters;

	void refreshPixmap();

	void showEvent(QShowEvent* const event) override;
};