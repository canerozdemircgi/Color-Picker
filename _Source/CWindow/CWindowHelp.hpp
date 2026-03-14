#pragma once

#include "CDialog/CDialogOk.hpp"

class CWindowHelp final : private CDialogOk
{
public:
	static QWidget& getInstance();

private:
	explicit CWindowHelp(QWidget* const parent);
};