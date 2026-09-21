#pragma once

#include "CDialog/CDialogOk.hpp"

class CWindowAbout final : private CDialogOk
{
public:
	static QWidget& getInstance();

private:
	explicit CWindowAbout(QWidget* const parent);
};