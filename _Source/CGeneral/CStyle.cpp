#include "CStyle.h"

extern QFont font;

const QFont CStyle::getFontTitle()
{
    QFont fontTitle(font);
    fontTitle.setPointSize(9);
    return fontTitle;
}

const QFont CStyle::fontTitle(CStyle::getFontTitle());

const QString CStyle::style("Fusion");
const QString CStyle::styleSheet(R"(
QWidget
{
background: #404040;
color: #c0c0c0;
}

QWidget[accessibleName="QMain"]
{
border: 1px solid #c0c0c0;
}

QFrame:disabled
{
color: #808080;
}

QLabel[accessibleName="QLabelHalf"]
{
border-top: 1px solid #808080;
border-bottom: 0 none #808080;
border-left: 1px solid #808080;
border-right: 1px solid #808080;
border-top-left-radius: 2px;
border-top-right-radius: 2px;
}

QLabel[accessibleName="QLabelImage"]
{
background: #606060;
border: 3px solid #606060;
border-radius: 2px;
}

QPushButton
{
background: #606060;
border: 1px solid #606060;
border-radius: 2px;
}

QPushButton:hover
{
background: #808080;
border: 1px solid #808080;
color: #2b2b2b;
}

QPushButton:pressed,
QPushButton:checked
{
background: #404040;
border: 1px solid #a0a0a0;
color: #c0c0c0;
}

QPushButton::menu-indicator
{
background: none;
}

QPushButton[accessibleName="QMenuButton"]
{
padding-left: -14px;
}

QPushButton:disabled
{
background: #606060;
border: 1px solid #606060;
color: #808080;
}

QCheckBox:disabled,
QRadioButton:disabled,
QMenu::item:disabled
{
color: #808080;
}

QCheckBox::indicator:checked:hover,
QCheckBox::indicator:unchecked:hover,
QRadioButton::indicator:checked:hover,
QRadioButton::indicator:unchecked:hover,
QSpinBox:hover,
QDoubleSpinBox:hover,
QLineEdit:hover,
QComboBox:hover
{
border: 1px solid #884;
}

QCheckBox::indicator:checked:focus,
QCheckBox::indicator:unchecked:focus,
QRadioButton::indicator:checked:focus,
QRadioButton::indicator:unchecked:focus,
QSpinBox:focus,
QDoubleSpinBox:focus,
QLineEdit:focus,
QComboBox:focus
{
border: 1px solid #484;
}

QCheckBox::indicator:disabled,
QRadioButton::indicator:disabled,
QSpinBox::up-button:disabled,
QDoubleSpinBox::up-button:disabled,
QSpinBox::down-button:disabled,
QDoubleSpinBox::down-button:disabled,
QComboBox::drop-down:disabled,
QComboBox::down-arrow:disabled,
QSpinBox::up-button:pressed,
QDoubleSpinBox::up-button:pressed,
QSpinBox::down-button:pressed,
QDoubleSpinBox::down-button:pressed,
QComboBox::drop-down:pressed,
QComboBox::down-arrow:pressed
{
background: #404040;
}

QCheckBox::indicator
{
background: #2b2b2b;
border: 1px solid #2b2b2b;
border-radius: 2px;
width: 9px;
height: 9px;
padding: 2px;
}

QCheckBox::indicator:checked
{
image: url(:/Button/Check.svg);
}

QCheckBox::indicator:checked:disabled
{
image: url(:/Button/Check-Disabled.svg);
}

QRadioButton::indicator
{
background: #2b2b2b;
border: 1px solid #2b2b2b;
border-radius: 7.499px;
width: 7px;
height: 7px;
padding: 3px;
}

QRadioButton::indicator:checked
{
image: url(:/Button/Radio.svg);
}

QRadioButton::indicator:checked:disabled
{
image: url(:/Button/Radio-Disabled.svg);
}

QLineEdit
{
padding-left: 2px;
padding-right: 2px;
}

QSpinBox,
QDoubleSpinBox,
QLineEdit,
QComboBox
{
background: #2b2b2b;
border: 1px solid #2b2b2b;
border-radius: 2px;
}

[hasTopBorderRadius=true]
{
border-bottom-left-radius: 0;
border-bottom-right-radius: 0;
}

[hasBottomBorderRadius=true]
{
border-top-left-radius: 0;
border-top-right-radius: 0;
}

[hasNoBorderRadius=true]
{
border-radius: 0;
}

QSpinBox:disabled,
QDoubleSpinBox:disabled,
QLineEdit::disabled,
QComboBox:disabled
{
background: #404040;
color: #808080;
}

:disabled[hasTopBorderRadius=true]
{
border-bottom: 0 none #808080;
}

:disabled[hasBottomBorderRadius=true]
{
border-top: 0 none #808080;
}

QSpinBox::up-button:hover,
QDoubleSpinBox::up-button:hover,
QSpinBox::down-button:hover,
QDoubleSpinBox::down-button:hover,
QComboBox::drop-down:hover,
QComboBox::down-arrow:hover
{
background: #606060;
}

QSpinBox::up-button,
QDoubleSpinBox::up-button,
QSpinBox::down-button,
QDoubleSpinBox::down-button,
QComboBox::drop-down
{
background: #505050;
border-radius: 2px;
width: 14px;
subcontrol-origin: padding;
}

QSpinBox::up-button,
QDoubleSpinBox::up-button
{
border-bottom-left-radius: 0;
border-bottom-right-radius: 0;
subcontrol-position: top right;
}

QSpinBox::down-button,
QDoubleSpinBox::down-button
{
border-top-left-radius: 0;
border-top-right-radius: 0;
subcontrol-position: bottom right;
}

QSpinBox::up-arrow,
QDoubleSpinBox::up-arrow
{
width: 6px;
height: 6px;
image: url(:/Direction/Up.svg);
}

QSpinBox::down-arrow,
QDoubleSpinBox::down-arrow,
QComboBox::down-arrow
{
width: 6px;
height: 6px;
image: url(:/Direction/Down.svg);
}

QSpinBox::up-arrow:disabled,
QSpinBox::up-arrow:off,
QDoubleSpinBox::up-arrow:disabled,
QDoubleSpinBox::up-arrow:off
{
image: url(:/Direction/Up-Disabled.svg);
}

QSpinBox::down-arrow:disabled,
QSpinBox::down-arrow:off,
QDoubleSpinBox::down-arrow:disabled,
QDoubleSpinBox::down-arrow:off,
QComboBox::down-arrow:disabled
{
image: url(:/Direction/Down-Disabled.svg);
}

QSpinBox[accessibleName="QInputNo"]::up-button,
QDoubleSpinBox[accessibleName="QInputNo"]::up-button,
QSpinBox[accessibleName="QInputNo"]::down-button,
QDoubleSpinBox[accessibleName="QInputNo"]::down-button,
QSpinBox[accessibleName="QInputNo"]::up-arrow,
QDoubleSpinBox[accessibleName="QInputNo"]::up-arrow,
QSpinBox[accessibleName="QInputNo"]::down-arrow,
QDoubleSpinBox[accessibleName="QInputNo"]::down-arrow
{
width: 0;
}

QComboBox QListView,
QMenu,
QToolTip
{
background: #404040;
border: 1px solid #c0c0c0;
color: #c0c0c0;
border-radius: 2px;
}

QMenu::icon
{
left: 5px;
}

QMenu::item
{
height: 25px;
padding: 0 20px 0 10px;
}

QMenu::item:selected
{
background: #2b2b2b;
}

QMenu::separator
{
background: #c0c0c0;
height: 1px;
margin: 10px;
}
)");