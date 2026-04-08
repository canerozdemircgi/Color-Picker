#include "CWindowMain.hpp"
#include "ui_CWindowMain.h"

#include "CConfiguration/CConfiguration.hpp"
#include "CGui/CUi.hpp"
#include "CSystem/CPlatform.hpp"
#include "CTitle/CTitleBar.tpp"
#include "CWidget/CPushButtonSta.tpp"
#include "CWindow/CWindowAbout.hpp"
#include "CWindow/CWindowHelp.hpp"

#include <QtGui/QWindow>
#include <QtGui/QWindowStateChangeEvent>

CWindowMain::CWindowMain(QWidget* const parent) :
	QWidget{parent},

	ui{CUi::newUi<Ui::CWindowMain>(this, {.windowType = Qt::WindowType::Window, .menu = CMenu::Parameters{}, .title = u"Color Picker by canerozdemircgi"_s, .atop = true, .dispose = false})},
	SimpleMode_PushButton{this->ui->TitleBar->addControlButton(u":/Button/Star.svg"_s, u"Simple Mode"_s, 1u, true, u"Advanced Mode"_s)}
{
	this->ui->TitleBar->addMenuAction(u":/Window/Settings.svg"_s, u"Settings"_s, []{});
	this->ui->TitleBar->addMenuAction(u":/Window/Help.svg"_s, u"Help"_s, []
	{
		QWidget& helpWindow = CWindowHelp::getInstance();
		helpWindow.show();
	});
	this->ui->TitleBar->addMenuAction(u":/Window/About.svg"_s, u"About"_s, []
	{
		QWidget& aboutWindow = CWindowAbout::getInstance();
		aboutWindow.show();
	});

	this->ui->Reset_PushButton->setMouseReleased([this]
	{
		CConfiguration::refresh(this, true);
	});
}

CWindowMain::~CWindowMain()
{
	delete this->ui;
}

void CWindowMain::showEvent(QShowEvent* const event)
{
	QWidget::showEvent(event);

	this->window()->windowHandle()->installEventFilter(this);
}

bool CWindowMain::eventFilter(QObject* const object, QEvent* const event)
{
	if (event->type() == QEvent::Type::WindowStateChange)
	{
		const QWindowStateChangeEvent* const windowStateChangeEvent = static_cast<const QWindowStateChangeEvent*>(event);

		const bool minimizedBefore = windowStateChangeEvent->oldState() & Qt::WindowState::WindowMinimized;
		const bool minimizedAfter = this->window()->windowHandle()->windowState() & Qt::WindowState::WindowMinimized;

		if (!minimizedBefore && minimizedAfter)
			CPlatform::setProcessPriority(CPlatform::Priority::LOW);
		else if (minimizedBefore && !minimizedAfter)
			CPlatform::setProcessPriority(CPlatform::Priority::HIGH);
	}

	return QWidget::eventFilter(object, event);
}