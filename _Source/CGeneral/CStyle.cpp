#include "CStyle.h"

const QFont CStyle::fontTitle(QFont("Roboto", 9));

const QString CStyle::style("Fusion");
const QString CStyle::styleSheet(1 + R"(
QWidget
{
background: #444;
color: #ccc;
}

QWidget[accessibleName="QMain"]
{
border: 1px solid #ccc;
}

QFrame:disabled
{
color: #888;
}

QLabel
{
selection-background-color: #f0f0f0;
selection-color: #101010;
}

QLabel[accessibleName="QLabelHalf"]
{
border-top: 1px solid #888;
border-bottom: 0 none #888;
border-left: 1px solid #888;
border-right: 1px solid #888;
border-top-left-radius: 2px;
border-top-right-radius: 2px;
}

QLabel[accessibleName="QLabelImage"]
{
background: #666;
border: 3px solid #666;
border-radius: 2px;
}

QPushButton
{
background: #666;
border: 1px solid #666;
border-radius: 2px;
}

QPushButton:hover
{
background: #888;
border: 1px solid #888;
color: #2b2b2b;
}

QPushButton:pressed,
QPushButton:checked
{
background: #444;
border: 1px solid #aaa;
color: #ccc;
}

QPushButton::menu-indicator
{
background: none;
}

QPushButton[accessibleName="QMenuButton"]
{
padding-left: -20px;
border-top-right-radius: 0;
border-bottom-right-radius: 16px;
}

QPushButton:disabled
{
background: #666;
border: 1px solid #666;
color: #888;
}

QCheckBox:disabled,
QRadioButton:disabled,
QMenu::item:disabled
{
color: #888;
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
background: #444;
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
image: url(:/Button/Check.png);
}

QCheckBox::indicator:checked:disabled
{
image: url(:/Button/Check-Disabled.png);
}

QRadioButton::indicator
{
background: #2b2b2b;
border: 1px solid #2b2b2b;
border-radius: 7px;
width: 7px;
height: 7px;
padding: 3px;
}

QRadioButton::indicator:checked
{
image: url(:/Button/Radio.png);
}

QRadioButton::indicator:checked:disabled
{
image: url(:/Button/Radio-Disabled.png);
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

QSpinBox:disabled,
QDoubleSpinBox:disabled,
QLineEdit::disabled,
QComboBox:disabled
{
background: #444;
color: #888;
}

QSpinBox::up-button:hover,
QDoubleSpinBox::up-button:hover,
QSpinBox::down-button:hover,
QDoubleSpinBox::down-button:hover,
QComboBox::drop-down:hover,
QComboBox::down-arrow:hover
{
background: #666;
}

QSpinBox::up-button,
QDoubleSpinBox::up-button,
QSpinBox::down-button,
QDoubleSpinBox::down-button,
QComboBox::drop-down
{
background: #555;
border-radius: 2px;
width: 14px;
subcontrol-origin: padding;
}

QSpinBox::up-button,
QDoubleSpinBox::up-button
{
subcontrol-position: top right;
}

QSpinBox::down-button,
QDoubleSpinBox::down-button
{
subcontrol-position: bottom right;
}

QSpinBox::up-arrow,
QDoubleSpinBox::up-arrow
{
width: 6px;
height: 6px;
image: url(:/Direction/Up.png);
}

QSpinBox::down-arrow,
QDoubleSpinBox::down-arrow,
QComboBox::down-arrow
{
width: 6px;
height: 6px;
image: url(:/Direction/Down.png);
}

QSpinBox::up-arrow:disabled,
QSpinBox::up-arrow:off,
QDoubleSpinBox::up-arrow:disabled,
QDoubleSpinBox::up-arrow:off
{
image: url(:/Direction/Up-Disabled.png);
}

QSpinBox::down-arrow:disabled,
QSpinBox::down-arrow:off,
QDoubleSpinBox::down-arrow:disabled,
QDoubleSpinBox::down-arrow:off,
QComboBox::down-arrow:disabled
{
image: url(:/Direction/Down-Disabled.png);
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
background: #444;
border: 1px solid #ccc;
color: #ccc;
border-radius: 2px;
}

QMenu::icon
{
left: 5px;
}

QMenu::item
{
height: 25px;
padding: 0 20px;
}

QMenu::item:selected
{
background: #2b2b2b;
}

QMenu::separator
{
background: #ccc;
height: 1px;
margin: 10px;
})");