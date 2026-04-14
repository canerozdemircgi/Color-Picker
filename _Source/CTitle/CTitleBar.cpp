#include "CTitleBar.hpp"
#include "ui_CTitleBar.h"

#include "CGui/CGui.hpp"
#include "CGui/CUi.hpp"
#include "CTitle/CWidgetMove.tpp"
#include "CTitle/CWidgetsSize.hpp"
#include "CWidget/CPushButtonSta.tpp"

#include <QtGui/QWindow>

CTitleBar::CTitleBar(QWidget* const parent) :
	QWidget{parent},

	ui{CUi::newUi<Ui::CTitleBar>(this)},
	menu{nullptr},
	sizeWidgets{*(new CWidgetsSize(parent))}
{
	CGui::makeFrameless(parent->parentWidget());
}

CTitleBar::~CTitleBar()
{
	delete this->ui;
}

void CTitleBar::initialize(const CTitleBar::Parameters& parameters)
{
	static const QIcon MENU_ICON(u":/Logo/ColorPicker.svg"_s);
	static const QIcon MAXIMIZE_ICON(u":/Direction/Up.svg"_s);
	static const QIcon NORMALIZE_ICON(u":/Direction/Down.svg"_s);

	this->window()->setWindowFlag(parameters.windowType);

	this->ui->Icon_PushButton->setIcon(parameters.icon.value_or(MENU_ICON));

	if (parameters.menu)
	{
		this->menu = new CMenu(this->ui->Icon_PushButton, *parameters.menu);

		this->ui->Icon_PushButton->setAccessibleName(u"CTitleBarButtonMenu"_s);
		this->ui->Icon_PushButton->setText(u"\u2004Menu"_s);

		this->ui->Icon_PushButton->setMouseReleased([this]
		{
			this->menu->toggle();
		});
	}
	else
	{
		this->ui->Icon_PushButton->setAccessibleName(u"CTitleBarButtonIcon"_s);
		this->ui->Icon_PushButton->setAttribute(Qt::WidgetAttribute::WA_TransparentForMouseEvents);
		this->ui->Icon_PushButton->setMinimumWidth(this->ui->Icon_PushButton->height());
	}

	this->ui->Title_Label->setText(parameters.title);

	if (parameters.atop)
	{
		this->ui->ATop_PushButton->setMouseReleased([this]
		{
			if (this->window()->windowHandle())
			{
				this->window()->windowHandle()->setFlag(Qt::WindowType::WindowStaysOnTopHint, this->ui->ATop_PushButton->isChecked());

				if (this->ui->ATop_PushButton->isChecked() && this->menu && this->menu->isVisible())
					this->menu->raise();
			}
			else
				this->window()->setWindowFlag(Qt::WindowType::WindowStaysOnTopHint, this->ui->ATop_PushButton->isChecked());
		});
	}
	else
		this->ui->ATop_PushButton->setVisible(false);

	if (parameters.minimize)
	{
		this->window()->setWindowFlag(Qt::WindowType::WindowMinimizeButtonHint);

		this->ui->Minimize_PushButton->setMouseReleased([this]
		{
			this->window()->windowHandle()->showMinimized();
		});
	}
	else
		this->ui->Minimize_PushButton->setVisible(false);

	if (parameters.maximize)
	{
		this->window()->setWindowFlag(Qt::WindowType::WindowMaximizeButtonHint);

		this->ui->Maximize_PushButton->setMouseReleased([this]
		{
			if (this->ui->Maximize_PushButton->isChecked())
			{
				if (this->window()->windowHandle())
				{
					this->geometryOriginal = this->window()->windowHandle()->geometry();
					this->window()->windowHandle()->setGeometry(CGui::availableGeometryCurrentScreen());
				}
				else
				{
					this->geometryOriginal = this->window()->geometry();
					this->window()->setGeometry(CGui::availableGeometryCurrentScreen());
				}

				this->ui->Maximize_PushButton->setIcon(NORMALIZE_ICON);
				this->ui->Maximize_PushButton->setToolTip(u"Normalize"_s);

				this->sizeWidgets.setVisible(false);
			}
			else
			{
				if (this->window()->windowHandle())
					this->window()->windowHandle()->setGeometry(this->geometryOriginal);
				else
					this->window()->setGeometry(this->geometryOriginal);
				this->geometryOriginal = {};

				this->ui->Maximize_PushButton->setIcon(MAXIMIZE_ICON);
				this->ui->Maximize_PushButton->setToolTip(u"Maximize"_s);

				this->sizeWidgets.setVisible(true);
			}
		});
		this->ui->Title_Widget->setMouseDoubleClicked([this]
		{
			this->ui->Maximize_PushButton->mousePressAndRelease();
		});
	}
	else
		this->ui->Maximize_PushButton->setVisible(false);

	if (parameters.close)
	{
		this->ui->Close_PushButton->setMouseReleased([this]
		{
			this->window()->windowHandle()->close();
		});
	}
	else
		this->ui->Close_PushButton->setVisible(false);

	if (parameters.dispose)
		this->window()->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
}

CPushButtonSta& CTitleBar::addControlButton(const QString& icon, const QString& tooltip, uint8_t index, bool checkable, const QString& tooltipChecked) const
{
	CPushButtonSta* const button = new CPushButtonSta(this->ui->Control_Widget);
	button->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
	button->setMinimumSize(30, 30);
	button->setIcon(QIcon{icon});
	button->setIconSize({14, 14});
	button->setToolTip(tooltip);
	button->setCheckable(checkable);
	this->ui->Control_Widget_Layout->insertWidget(index, button);

	if (checkable && !tooltipChecked.isEmpty())
	{
		QObject::connect(button, &QAbstractButton::toggled, [button, tooltip, tooltipChecked]
		{
			button->setToolTip(button->isChecked() ? tooltipChecked : tooltip);
		});
	}

	return *button;
}

QRect CTitleBar::getGeometry() const
{
	if (!this->geometryOriginal.isEmpty())
		return this->geometryOriginal;
	return this->window()->windowHandle()->geometry();
}