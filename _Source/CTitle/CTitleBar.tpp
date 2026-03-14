#pragma once

#include "CTitleBar.hpp"
#include "ui_CTitleBar.h"

#include "CGui/CSvg.hpp"
#include "CMenu/CMenu.hpp"

template <CLambda::CCallable<void> Function>
void CTitleBar::addMenuAction(const QString& icon, const QString& text, Function&& function) const
{
	QObject::connect(this->menu->addAction(CSvg::createPixmap({{{.path = icon}}, {.width = 12, .height = 12}}), text), &QAction::triggered, [this, function = std::move(function)]
	{
		this->ui->Icon_PushButton->mousePressAndRelease();
		function();
	});
}