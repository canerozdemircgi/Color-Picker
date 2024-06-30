#include "../CMainWindow.h"

#include "../CDialog/CConfig.h"
#include "../CGeneral/CCore.h"

void CMainWindow::LinkStateStatic()
{
	connect(Title_QMenu.addAction(QPixmap(":/Direction/Right.svg").scaled(10, 10, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation), "Configuration"), &QAction::triggered, this, &CMainWindow::State_Config_QAction_triggered, CCore::connection);
	connect(Title_QMenu.addAction("Help"), &QAction::triggered, this, &CMainWindow::State_Help_QAction_triggered, CCore::connection);
	connect(Title_QMenu.addAction("About"), &QAction::triggered, this, &CMainWindow::State_About_QAction_triggered, CCore::connection);

	Icon_QPushButton.MouseLeftReleased = std::bind(&CMainWindow::State_Icon_QPushButton_MouseLeftReleased, this);

	connect(&Simple_QPushButton, &QAbstractButton::toggled, this, &CMainWindow::State_Simple_QPushButton_toggled, CCore::connection);
	connect(&ATop_QPushButton, &QAbstractButton::toggled, this, &CMainWindow::State_ATop_QPushButton_toggled, CCore::connection);
	connect(&ATop_QPushButton, &QAbstractButton::released, this, &CMainWindow::show, CCore::connection);
	Minimize_QPushButton.MouseLeftReleased = std::bind(&CMainWindow::showMinimized, this);
	Close_QPushButton.MouseLeftReleased = std::bind(reinterpret_cast<bool(CMainWindow::*)()>(&CMainWindow::close), this);

	connect(&XMin_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &XMin_QDSpinBox, &CDoubleSpinBox_Space::ValueChanged, CCore::connection);
	connect(&XMax_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &XMax_QDSpinBox, &CDoubleSpinBox_Space::ValueChanged, CCore::connection);
	connect(&YMin_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &YMin_QDSpinBox, &CDoubleSpinBox_Space::ValueChanged, CCore::connection);
	connect(&YMax_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &YMax_QDSpinBox, &CDoubleSpinBox_Space::ValueChanged, CCore::connection);
	connect(&ZMin_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &ZMin_QDSpinBox, &CDoubleSpinBox_Space::ValueChanged, CCore::connection);
	connect(&ZMax_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &ZMax_QDSpinBox, &CDoubleSpinBox_Space::ValueChanged, CCore::connection);
	connect(&WMin_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &WMin_QDSpinBox, &CDoubleSpinBox_Space::ValueChanged, CCore::connection);
	connect(&WMax_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &WMax_QDSpinBox, &CDoubleSpinBox_Space::ValueChanged, CCore::connection);

	RGB_QRadioButton.Toggled = std::bind(&CMainWindow::State_RGB_QRadioButton_Toggled, this);
	GRY_QRadioButton.Toggled = std::bind(&CMainWindow::State_GRY_QRadioButton_Toggled, this);
	HSL_QRadioButton.Toggled = std::bind(&CMainWindow::State_HSL_QRadioButton_Toggled, this);
	HSV_QRadioButton.Toggled = std::bind(&CMainWindow::State_HSV_QRadioButton_Toggled, this);

	connect(&Alpha_QCheckBox, &QAbstractButton::toggled, this, &CMainWindow::State_Alpha_QCheckBox_toggled, CCore::connection);
	connect(&Alpha_QComboBox, static_cast<void(QComboBox::*)(const int)>(&QComboBox::currentIndexChanged), this, &CMainWindow::State_Alpha_QComboBox_currentIndexChanged, CCore::connection);
	connect(&Float_QCheckBox, &QAbstractButton::toggled, this, &CMainWindow::State_Float_QCheckBox_toggled, CCore::connection);
	connect(&Gamma_QCheckBox, &QAbstractButton::toggled, this, &CMainWindow::State_Gamma_QCheckBox_toggled, CCore::connection);
	connect(&Gamma_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), this, &CMainWindow::State_Gamma_QDSpinBox_valueChanged, CCore::connection);

	Pick_QPushButton.MouseLeftPressed = std::bind(&CMainWindow::State_Pick_QPushButton_MouseLeftPressed, this);
	Pick_QPushButton.MouseRightPressed = std::bind(&CMainWindow::State_Pick_QPushButton_MouseRightPressed, this);
	Pick_QPushButton.MouseMiddlePressed = std::bind(&CMainWindow::State_Pick_QPushButton_MouseMiddlePressed, this);
	Pick_QPushButton.MouseReleased = std::bind(&CMainWindow::State_Pick_QPushButton_MouseReleased, this);
	Pick_QPushButton.MouseMoved = std::bind(&CMainWindow::State_Pick_QPushButton_MouseMoved, this);

	connect(&RGB1_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &RGB1_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&RGB2_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &RGB2_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&RGB3_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &RGB3_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&HSL1_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &HSL1_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&HSL2_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &HSL2_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&HSL3_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &HSL3_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&HSV1_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &HSV1_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&HSV2_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &HSV2_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&HSV3_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &HSV3_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&LUMI_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &LUMI_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&INTP_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &INTP_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);
	connect(&ALPH_QDSpinBox, static_cast<void(QDoubleSpinBox::*)(const double)>(&QDoubleSpinBox::valueChanged), &ALPH_QDSpinBox, &CDoubleSpinBox_Info::ValueChanged, CCore::connection);

	RGB1_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_RGB1_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	RGB2_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_RGB2_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	RGB3_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_RGB3_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	HSL1_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_HSL1_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	HSL2_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_HSL2_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	HSL3_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_HSL3_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	HSV1_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_HSV1_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	HSV2_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_HSV2_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	HSV3_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_HSV3_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	LUMI_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_LUMI_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	INTP_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_INTP_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);

	connect(&Name_QLineEdit, &QLineEdit::textEdited, this, &CMainWindow::State_Name_QLineEdit_textEdited, CCore::connection);
	connect(&Tag_QLineEdit, &QLineEdit::textEdited, this, &CMainWindow::State_Tag_QLineEdit_textEdited, CCore::connection);
	connect(&Hex_QLineEdit, &QLineEdit::returnPressed, this, &CMainWindow::State_Hex_QLineEdit_returnPressed, CCore::connection);

	Load_QPushButton.MouseLeftReleased = std::bind(&CMainWindow::State_Load_QPushButton_MouseLeftReleased, this);
	Save_QPushButton.MouseLeftReleased = std::bind(&CMainWindow::State_Save_QPushButton_MouseLeftReleased, this);
	Reset_QPushButton.MouseLeftReleased = std::bind(&CMainWindow::State_Reset_QPushButton_MouseLeftReleased, this);
	Reset_QPushButton.MouseRightReleased = std::bind(&CMainWindow::State_Reset_QPushButton_MouseRightReleased, this);
	Invert_QPushButton.MouseLeftReleased = std::bind(&CMainWindow::State_Invert_QPushButton_MouseLeftReleased, this);
	Invert_QPushButton.MouseRightReleased = std::bind(&CMainWindow::State_Invert_QPushButton_MouseRightReleased, this);
	Empty_QPushButton.MouseLeftReleased = std::bind(&CMainWindow::State_Empty_QPushButton_MouseLeftReleased, this);
	Empty_QPushButton.MouseRightReleased = std::bind(&CMainWindow::State_Empty_QPushButton_MouseRightReleased, this);
	Random_QPushButton.MouseLeftReleased = std::bind(&CMainWindow::State_Random_QPushButton_MouseLeftReleased, this);
	Random_QPushButton.MouseRightReleased = std::bind(&CMainWindow::State_Random_QPushButton_MouseRightReleased, this);
	Random_QPushButton.MouseMiddleReleased = std::bind(&CMainWindow::State_Random_QPushButton_MouseMiddleReleased, this);

	CWidget_Slot::MouseLeftPressed = std::bind(static_cast<void(CMainWindow::*)()>(&CMainWindow::RefreshAll), this);
	CWidget_Slot::MouseWheeled = std::bind(&CMainWindow::State_Slot_MouseWheeled, this, std::placeholders::_1);
}

void CMainWindow::LinkStateDynamic()
{
	ALPH_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_ALPH_RGB_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);

	Blocks_QWidget.XBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_RGB1_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	Blocks_QWidget.YBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_RGB2_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	Blocks_QWidget.ZBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_RGB3_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	Blocks_QWidget.WBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_ALPH_RGB_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);

	RandomColor = std::bind(&CMainWindow::RandomColorRGB, this);
	RefreshHex = std::bind(&CMainWindow::RefreshHex3, this);
	RefreshBlock = std::bind(&CMainWindow::RefreshBlock3RGB, this);
}