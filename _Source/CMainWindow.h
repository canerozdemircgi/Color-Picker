#ifndef CMainWindow_H
#define CMainWindow_H

#include "CWindow/CMagnifier.h"
#include "CWindow/CMainWindowUI.h"

#include <opencv2/imgproc/imgproc.hpp>

class CMainWindow final : public CMainWindowUI
{
	Q_OBJECT

public:
	CMainWindow();

private:
	static constexpr int colorModeSize = 4;
	CRadioButton_Mode *__restrict__ colorModes[colorModeSize];
	static constexpr int colorSlotSize = 64;
	CWidget_Slot *__restrict__ colorSlots[colorSlotSize];

	void InitializeArrays();
	void LinkStateStatic();
	void LinkStateDynamic();

	void ConfigReset() const;
	const bool ConfigLoad();
	void ConfigSave() const;

	std::function<QColor()> RandomColor;
	[[nodiscard]] std::unique_ptr<const QColor> RandomColorRGB() const;
	[[nodiscard]] std::unique_ptr<const QColor> RandomColorGRY() const;
	[[nodiscard]] std::unique_ptr<const QColor> RandomColorHSL() const;
	[[nodiscard]] std::unique_ptr<const QColor> RandomColorHSV() const;

	void RefreshAll();

	std::function<void()> RefreshHex;
	void RefreshHex3();
	void RefreshHex4RGBA();
	void RefreshHex4ARGB();

	void RefreshSpinBoxState();

	std::function<void()> RefreshBlock;
	void RefreshBlock3RGB();
	void RefreshBlock3GRY();
	void RefreshBlock3HSL();
	void RefreshBlock3HSV();
	void RefreshBlock4();

	void State_FloatPrec_QSpinBox_valueChanged(const int value);

	void State_RGB1_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_RGB2_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_RGB3_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_HSL1_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_HSL2_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_HSL3_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_HSV1_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_HSV2_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_HSV3_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_LUMI_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_INTP_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_ALPH_RGB_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_ALPH_GRY_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_ALPH_HSL_QDSpinBox_ValueChangedNotBySet(const int value);
	void State_ALPH_HSV_QDSpinBox_ValueChangedNotBySet(const int value);

	void State_Pick_QPushButton_MouseMiddlePressed();
	void State_Pick_QPushButton_MouseRightPressed();
	void State_Pick_QPushButton_MouseLeftPressed();
	void State_Pick_QPushButton_MouseMoved() const;
	void State_Pick_QPushButton_MouseReleased() const;

	void State_Magnifier_MouseMoved(const QColor &__restrict__ pick, const QString &__restrict__ coord);
	void RefreshAll(const QColor &__restrict__ color);

	void State_Empty_QPushButton_MouseLeftReleased();
	void State_Empty_QPushButton_MouseRightReleased();
	void State_Random_QPushButton_MouseLeftReleased();
	void State_Random_QPushButton_MouseRightReleased();
	void State_Random_QPushButton_MouseMiddleReleased();
	void State_Slot_MouseWheeled(const int delta);
	void State_Invert_QPushButton_MouseLeftReleased();
	void State_Invert_QPushButton_MouseRightReleased();

	void State_Load_QPushButton_MouseLeftReleased();
	void Load_QPushButton_MouseLeftReleased(const QString &__restrict__ fileName);
	void State_Save_QPushButton_MouseLeftReleased();
	void State_Reset_QPushButton_MouseLeftReleased();
	void State_Reset_QPushButton_MouseRightReleased();

	void State_Icon_QPushButton_MouseLeftReleased();
	void closeEvent(QCloseEvent *__restrict__ event) override;

	void State_RGB_QRadioButton_Toggled();
	void State_GRY_QRadioButton_Toggled();
	void State_HSL_QRadioButton_Toggled();
	void State_HSV_QRadioButton_Toggled();

	CMagnifier *__restrict__ magnifier;
	cv::InterpolationFlags State_Magnifier_MouseRightPressed();
	const bool State_Magnifier_MouseMiddlePressed();
	void State_Magnifier_MouseWheeled(const double magRatio);

private slots:
	void State_Config_QAction_triggered();
	void State_Help_QAction_triggered() const;
	void State_About_QAction_triggered() const;

	void State_Simple_QPushButton_toggled(const bool checked);
	void State_ATop_QPushButton_toggled(const bool checked);

	void State_Alpha_QCheckBox_toggled(const bool checked);
	void State_Alpha_QComboBox_currentIndexChanged(const int index);
	void State_Float_QCheckBox_toggled(const bool checked);
	void State_Gamma_QCheckBox_toggled(const bool checked);
	void State_Gamma_QDSpinBox_valueChanged(const double value);

	void State_Name_QLineEdit_textEdited(const QString &__restrict__ arg);
	void State_Tag_QLineEdit_textEdited(const QString &__restrict__ arg);
	void State_Hex_QLineEdit_returnPressed();
};

#endif