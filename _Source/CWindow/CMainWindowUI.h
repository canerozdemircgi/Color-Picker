#ifndef CMainWindowUI_H
#define CMainWindowUI_H

#include "../CButton/CPushButton_Pick.h"
#include "../CButton/CPushButton_Sta.h"
#include "../CButton/CRadioButton_Mode.h"
#include "../CInput/CDoubleSpinBox_Info.h"
#include "../CInput/CDoubleSpinBox_Space.h"
#include "../CLabel/CLabel_Title.h"
#include "../CMenu/CMenu_Main.h"
#include "../CWidget/CWidget_Blocks.h"
#include "../CWidget/CWidget_Slots.h"

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>

class CMainWindowUI : public QWidget
{
protected:
	CMainWindowUI();

	QWidget Style_QWidget;

	CLabel_Title Title_QLabel;
	CMenu_Main Title_QMenu;
	CPushButton_Sta Icon_QPushButton;

	QPushButton Simple_QPushButton;
	QPushButton ATop_QPushButton;
	CPushButton_Sta Minimize_QPushButton;
	CPushButton_Sta Close_QPushButton;

	QWidget Space_QWidget;
	QLabel X_QLabel;
	QLabel Y_QLabel;
	QLabel Z_QLabel;
	QLabel W_QLabel;
	CDoubleSpinBox_Space XMin_QDSpinBox;
	CDoubleSpinBox_Space XMax_QDSpinBox;
	CDoubleSpinBox_Space YMin_QDSpinBox;
	CDoubleSpinBox_Space YMax_QDSpinBox;
	CDoubleSpinBox_Space ZMin_QDSpinBox;
	CDoubleSpinBox_Space ZMax_QDSpinBox;
	CDoubleSpinBox_Space WMin_QDSpinBox;
	CDoubleSpinBox_Space WMax_QDSpinBox;
	CRadioButton_Mode RGB_QRadioButton;
	CRadioButton_Mode GRY_QRadioButton;
	CRadioButton_Mode HSL_QRadioButton;
	CRadioButton_Mode HSV_QRadioButton;
	QFrame QLine_1;

	QWidget Simple_QWidget;
	QCheckBox Alpha_QCheckBox;
	QComboBox Alpha_QComboBox;
	QCheckBox Float_QCheckBox;
	QCheckBox Gamma_QCheckBox;
	QDoubleSpinBox Gamma_QDSpinBox;
	QCheckBox MagnifyInvert_QCheckBox;

	QSpinBox MagnifyResX_QSpinBox;
	QSpinBox MagnifyResY_QSpinBox;
	QDoubleSpinBox MagnifyRat_QDSpinBox;
	QComboBox MagnifyQuality_QComboBox;
	CPushButton_Pick Pick_QPushButton;
	QFrame QLine_2;

	QLabel RGB_QLabel;
	QLabel HSL_QLabel;
	QLabel HSV_QLabel;
	QLabel LUM_QLabel;
	QLabel INT_QLabel;
	QLabel ALP_QLabel;
	QLabel NTH_QLabel;
	CDoubleSpinBox_Info RGB1_QDSpinBox;
	CDoubleSpinBox_Info RGB2_QDSpinBox;
	CDoubleSpinBox_Info RGB3_QDSpinBox;
	CDoubleSpinBox_Info HSL1_QDSpinBox;
	CDoubleSpinBox_Info HSL2_QDSpinBox;
	CDoubleSpinBox_Info HSL3_QDSpinBox;
	CDoubleSpinBox_Info HSV1_QDSpinBox;
	CDoubleSpinBox_Info HSV2_QDSpinBox;
	CDoubleSpinBox_Info HSV3_QDSpinBox;
	CDoubleSpinBox_Info LUMI_QDSpinBox;
	CDoubleSpinBox_Info INTP_QDSpinBox;
	CDoubleSpinBox_Info ALPH_QDSpinBox;
	QLineEdit Name_QLineEdit;
	QLineEdit Tag_QLineEdit;
	QLineEdit Hex_QLineEdit;

	QWidget Button_QWidget;
	CPushButton_Sta Load_QPushButton;
	CPushButton_Sta Save_QPushButton;
	CPushButton_Sta Reset_QPushButton;
	CPushButton_Sta Invert_QPushButton;
	CPushButton_Sta Empty_QPushButton;
	CPushButton_Sta Random_QPushButton;
	QFrame QLine_3;
	QFrame QLine_4;

	QFrame QLineBorder_5;

	CWidget_Blocks Blocks_QWidget;
	CWidget_Slots Slots_QWidget;

	QLabel SlotBack_QLabel;
	QWidget Slot_QWidget;
	QLabel SlotMask_QLabel;
};

#endif