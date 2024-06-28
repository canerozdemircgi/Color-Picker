#include "CMainWindowUI.h"

#include "../CGeneral/CStyle.h"

#include <QtGui/QScreen>
#include <QtWidgets/QApplication>

#include <opencv2/imgproc/imgproc.hpp>

CMainWindowUI::CMainWindowUI() :
	QWidget(),

	Style_QWidget(this),

	Title_QLabel(&Style_QWidget),
	Title_QMenu(&Style_QWidget),
	Icon_QPushButton(&Style_QWidget),

	Simple_QPushButton(&Style_QWidget),
	ATop_QPushButton(&Style_QWidget),
	Minimize_QPushButton(&Style_QWidget),
	Close_QPushButton(&Style_QWidget),

	Space_QWidget(&Style_QWidget),
	X_QLabel(&Space_QWidget),
	Y_QLabel(&Space_QWidget),
	Z_QLabel(&Space_QWidget),
	W_QLabel(&Space_QWidget),
	XMin_QDSpinBox(255, &Space_QWidget),
	XMax_QDSpinBox(255, &Space_QWidget),
	YMin_QDSpinBox(255, &Space_QWidget),
	YMax_QDSpinBox(255, &Space_QWidget),
	ZMin_QDSpinBox(255, &Space_QWidget),
	ZMax_QDSpinBox(255, &Space_QWidget),
	WMin_QDSpinBox(255, &Space_QWidget),
	WMax_QDSpinBox(255, &Space_QWidget),
	RGB_QRadioButton(0, &Space_QWidget),
	GRY_QRadioButton(1, &Space_QWidget),
	HSL_QRadioButton(2, &Space_QWidget),
	HSV_QRadioButton(3, &Space_QWidget),
	QLine_1(&Space_QWidget),

	Simple_QWidget(&Style_QWidget),
	Alpha_QCheckBox(&Simple_QWidget),
	Alpha_QComboBox(&Simple_QWidget),
	Float_QCheckBox(&Simple_QWidget),
	Gamma_QCheckBox(&Simple_QWidget),
	Gamma_QDSpinBox(&Simple_QWidget),
	MagnifyInvert_QCheckBox(&Simple_QWidget),

	MagnifyResX_QSpinBox(&Simple_QWidget),
	MagnifyResY_QSpinBox(&Simple_QWidget),
	MagnifyRat_QDSpinBox(&Simple_QWidget),
	MagnifyQuality_QComboBox(&Simple_QWidget),
	Pick_QPushButton(&Simple_QWidget),
	QLine_2(&Simple_QWidget),

	RGB_QLabel(&Simple_QWidget),
	HSL_QLabel(&Simple_QWidget),
	HSV_QLabel(&Simple_QWidget),
	LUM_QLabel(&Simple_QWidget),
	INT_QLabel(&Simple_QWidget),
	ALP_QLabel(&Simple_QWidget),
	NTH_QLabel(&Simple_QWidget),
	RGB1_QDSpinBox(255, &Simple_QWidget),
	RGB2_QDSpinBox(255, &Simple_QWidget),
	RGB3_QDSpinBox(255, &Simple_QWidget),
	HSL1_QDSpinBox(359, &Simple_QWidget),
	HSL2_QDSpinBox(255, &Simple_QWidget),
	HSL3_QDSpinBox(255, &Simple_QWidget),
	HSV1_QDSpinBox(359, &Simple_QWidget),
	HSV2_QDSpinBox(255, &Simple_QWidget),
	HSV3_QDSpinBox(255, &Simple_QWidget),
	LUMI_QDSpinBox(255, &Simple_QWidget),
	INTP_QDSpinBox(255, &Simple_QWidget),
	ALPH_QDSpinBox(255, &Simple_QWidget),
	Name_QLineEdit(&Simple_QWidget),
	Tag_QLineEdit(&Simple_QWidget),
	Hex_QLineEdit(&Simple_QWidget),

	Button_QWidget(&Style_QWidget),
	Load_QPushButton(&Button_QWidget),
	Save_QPushButton(&Button_QWidget),
	Reset_QPushButton(&Button_QWidget),
	Invert_QPushButton(&Button_QWidget),
	Empty_QPushButton(&Button_QWidget),
	Random_QPushButton(&Button_QWidget),
	QLine_3(&Button_QWidget),
	QLine_4(&Button_QWidget),

	QLineBorder_5(&Style_QWidget),

	Blocks_QWidget(this),
	Slots_QWidget(this),

	SlotBack_QLabel(this),
	Slot_QWidget(this),
	SlotMask_QLabel(this)
{
	QPoint center = QGuiApplication::screenAt(QCursor::pos())->geometry().center();
	setGeometry(center.x() - 500 / 2,
				center.y() - 620 / 2,
				500,
				620);

	setWindowFlag(Qt::WindowType::FramelessWindowHint);

	Style_QWidget.setGeometry(0, 0, 500, 620);
	Style_QWidget.setAccessibleName("QMain");

	Title_QLabel.setGeometry(1, 1, 498, 29);
	Title_QLabel.setIndent(90);
	Title_QLabel.setFont(CStyle::fontTitle);
	Title_QLabel.setText("Color-Picker");
	Icon_QPushButton.setGeometry(2, 2, 79, 27);
	Icon_QPushButton.setText(QString::fromUtf8("\u00A0") + "Menu");
	Icon_QPushButton.setIcon(QPixmap(":/Logo/Color Picker.svg"));
	Icon_QPushButton.setIconSize(QSize(18, 18));
	Icon_QPushButton.setAccessibleName("QMenuButton");

	Simple_QPushButton.setGeometry(363, 2, 33, 27);
	Simple_QPushButton.setCheckable(true);
	Simple_QPushButton.setIcon(QPixmap(":/Button/Star.svg"));
	Simple_QPushButton.setToolTip("Simple Mode");
	Simple_QPushButton.setToolTipDuration(60000);
	ATop_QPushButton.setGeometry(397, 2, 33, 27);
	ATop_QPushButton.setCheckable(true);
	ATop_QPushButton.setIcon(QPixmap(":/Button/Spiral.svg"));
	ATop_QPushButton.setToolTip("Always On Top");
	ATop_QPushButton.setToolTipDuration(60000);
	Minimize_QPushButton.setGeometry(431, 2, 33, 27);
	Minimize_QPushButton.setIcon(QPixmap(":/Direction/Left.svg"));
	Minimize_QPushButton.setToolTip("Minimize");
	Minimize_QPushButton.setToolTipDuration(60000);
	Close_QPushButton.setGeometry(465, 2, 33, 27);
	Close_QPushButton.setIcon(QPixmap(":/Button/Radio.svg"));
	Close_QPushButton.setToolTip("Close");
	Close_QPushButton.setToolTipDuration(60000);

	Space_QWidget.setGeometry(10, 40, 310, 110);
	X_QLabel.setGeometry(0, 0, 70, 20);
	X_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	X_QLabel.setText("Space R");
	X_QLabel.setAccessibleName("QLabelHalf");
	Y_QLabel.setGeometry(80, 0, 70, 20);
	Y_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	Y_QLabel.setText("Space G");
	Y_QLabel.setAccessibleName("QLabelHalf");
	Z_QLabel.setGeometry(160, 0, 70, 20);
	Z_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	Z_QLabel.setText("Space B");
	Z_QLabel.setAccessibleName("QLabelHalf");
	W_QLabel.setEnabled(false);
	W_QLabel.setGeometry(240, 0, 70, 20);
	W_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	W_QLabel.setText("Space A");
	W_QLabel.setAccessibleName("QLabelHalf");
	XMin_QDSpinBox.setGeometry(0, 30, 70, 20);
	XMin_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    XMin_QDSpinBox.setProperty("hasTopBorderRadius", true);
	XMax_QDSpinBox.setGeometry(0, 50, 70, 20);
	XMax_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    XMax_QDSpinBox.setProperty("hasBottomBorderRadius", true);
	YMin_QDSpinBox.setGeometry(80, 30, 70, 20);
	YMin_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    YMin_QDSpinBox.setProperty("hasTopBorderRadius", true);
	YMax_QDSpinBox.setGeometry(80, 50, 70, 20);
	YMax_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    YMax_QDSpinBox.setProperty("hasBottomBorderRadius", true);
	ZMin_QDSpinBox.setGeometry(160, 30, 70, 20);
	ZMin_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    ZMin_QDSpinBox.setProperty("hasTopBorderRadius", true);
	ZMax_QDSpinBox.setGeometry(160, 50, 70, 20);
	ZMax_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    ZMax_QDSpinBox.setProperty("hasBottomBorderRadius", true);
	WMin_QDSpinBox.setEnabled(false);
	WMin_QDSpinBox.setGeometry(240, 30, 70, 20);
	WMin_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    WMin_QDSpinBox.setProperty("hasTopBorderRadius", true);
	WMax_QDSpinBox.setEnabled(false);
	WMax_QDSpinBox.setGeometry(240, 50, 70, 20);
	WMax_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    WMax_QDSpinBox.setProperty("hasBottomBorderRadius", true);
	RGB_QRadioButton.setGeometry(0, 90, 70, 20);
	RGB_QRadioButton.setText("RGB");
	GRY_QRadioButton.setGeometry(80, 90, 70, 20);
	GRY_QRadioButton.setText("GRY");
	HSL_QRadioButton.setGeometry(160, 90, 70, 20);
	HSL_QRadioButton.setText("HSL");
	HSV_QRadioButton.setGeometry(240, 90, 70, 20);
	HSV_QRadioButton.setText("HSV");
	RGB_QRadioButton.setChecked(true);
	QLine_1.setEnabled(false);
	QLine_1.setGeometry(0, 80, 310, 1);
	QLine_1.setFrameShadow(QFrame::Shadow::Plain);
	QLine_1.setFrameShape(QFrame::Shape::HLine);

	Simple_QWidget.setGeometry(10, 160, 310, 280);
	Alpha_QCheckBox.setGeometry(0, 0, 70, 20);
	Alpha_QCheckBox.setText("Alpha");
	Alpha_QComboBox.setEnabled(false);
	Alpha_QComboBox.setGeometry(80, 0, 70, 20);
	Alpha_QComboBox.insertItems(0, QList<QString>()
								<< "XYZW"
								<< "WXYZ"
								);
	Float_QCheckBox.setGeometry(0, 30, 70, 20);
	Float_QCheckBox.setText("Float");
	Gamma_QCheckBox.setEnabled(false);
	Gamma_QCheckBox.setGeometry(80, 30, 70, 20);
	Gamma_QCheckBox.setText("Gamma");
	Gamma_QDSpinBox.setEnabled(false);
	Gamma_QDSpinBox.setGeometry(160, 30, 70, 20);
	Gamma_QDSpinBox.setMinimum(1.0);
	Gamma_QDSpinBox.setMaximum(100.0);
	Gamma_QDSpinBox.setSingleStep(0.1);
	Gamma_QDSpinBox.setPrefix("1/");
	Gamma_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
	Gamma_QDSpinBox.setAccessibleName("QInputNo");
	MagnifyInvert_QCheckBox.setGeometry(240, 60, 70, 20);
	MagnifyInvert_QCheckBox.setText("Invert");

	MagnifyResX_QSpinBox.setGeometry(80, 60, 70, 20);
	MagnifyResX_QSpinBox.setMinimum(64);
	MagnifyResX_QSpinBox.setMaximum(16384);
	MagnifyResX_QSpinBox.setSuffix("u");
	MagnifyResX_QSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
	MagnifyResX_QSpinBox.setAccessibleName("QInputNo");
	MagnifyResY_QSpinBox.setGeometry(80, 90, 70, 20);
	MagnifyResY_QSpinBox.setMinimum(64);
	MagnifyResY_QSpinBox.setMaximum(16384);
	MagnifyResY_QSpinBox.setSuffix("v");
	MagnifyResY_QSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
	MagnifyResY_QSpinBox.setAccessibleName("QInputNo");
	MagnifyRat_QDSpinBox.setGeometry(160, 60, 70, 20);
	MagnifyRat_QDSpinBox.setMinimum(1.0);
	MagnifyRat_QDSpinBox.setMaximum(1024.0);
	MagnifyRat_QDSpinBox.setSingleStep(0.125);
	MagnifyRat_QDSpinBox.setPrefix("*");
	MagnifyRat_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
	MagnifyRat_QDSpinBox.setAccessibleName("QInputNo");
	MagnifyQuality_QComboBox.setGeometry(160, 90, 70, 20);
	MagnifyQuality_QComboBox.insertItems(0, QList<QString>()
		<< "Nearest"
        << "Area"
		<< "Linear"
		<< "Cubic"
		<< "Lanczos"
	);
	MagnifyQuality_QComboBox.setItemData(0, cv::InterpolationFlags::INTER_NEAREST);
    MagnifyQuality_QComboBox.setItemData(1, cv::InterpolationFlags::INTER_AREA);
    MagnifyQuality_QComboBox.setItemData(2, cv::InterpolationFlags::INTER_LINEAR);
	MagnifyQuality_QComboBox.setItemData(3, cv::InterpolationFlags::INTER_CUBIC);
	MagnifyQuality_QComboBox.setItemData(4, cv::InterpolationFlags::INTER_LANCZOS4);
	Pick_QPushButton.setGeometry(0, 60, 70, 50);
	Pick_QPushButton.setText("PICK");
	Pick_QPushButton.setCursor(Qt::CursorShape::PointingHandCursor);
	QLine_2.setEnabled(false);
	QLine_2.setGeometry(0, 120, 310, 1);
	QLine_2.setFrameShadow(QFrame::Shadow::Plain);
	QLine_2.setFrameShape(QFrame::Shape::HLine);

	RGB_QLabel.setGeometry(0, 130, 70, 20);
	RGB_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	RGB_QLabel.setText("RGB");
	RGB_QLabel.setAccessibleName("QLabelHalf");
	HSL_QLabel.setGeometry(80, 130, 70, 20);
	HSL_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	HSL_QLabel.setText("HSL");
	HSL_QLabel.setAccessibleName("QLabelHalf");
	HSV_QLabel.setGeometry(160, 130, 70, 20);
	HSV_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	HSV_QLabel.setText("HSV");
	HSV_QLabel.setAccessibleName("QLabelHalf");
	LUM_QLabel.setGeometry(0, 230, 70, 20);
	LUM_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	LUM_QLabel.setText("Lumin");
	LUM_QLabel.setAccessibleName("QLabelHalf");
	INT_QLabel.setGeometry(80, 230, 70, 20);
	INT_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	INT_QLabel.setText("Inter");
	INT_QLabel.setAccessibleName("QLabelHalf");
	ALP_QLabel.setEnabled(false);
	ALP_QLabel.setGeometry(160, 230, 70, 20);
	ALP_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	ALP_QLabel.setText("Alpha");
	ALP_QLabel.setAccessibleName("QLabelHalf");
	NTH_QLabel.setGeometry(240, 130, 70, 20);
	NTH_QLabel.setAlignment(Qt::AlignmentFlag::AlignCenter);
	NTH_QLabel.setText("NTH");
	NTH_QLabel.setAccessibleName("QLabelHalf");
	RGB1_QDSpinBox.setGeometry(0, 160, 70, 20);
	RGB1_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    RGB1_QDSpinBox.setProperty("hasTopBorderRadius", true);
	RGB2_QDSpinBox.setGeometry(0, 180, 70, 20);
	RGB2_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    RGB2_QDSpinBox.setProperty("hasNoBorderRadius", true);
	RGB3_QDSpinBox.setGeometry(0, 200, 70, 20);
	RGB3_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    RGB3_QDSpinBox.setProperty("hasBottomBorderRadius", true);
	HSL1_QDSpinBox.setGeometry(80, 160, 70, 20);
	HSL1_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    HSL1_QDSpinBox.setProperty("hasTopBorderRadius", true);
	HSL2_QDSpinBox.setGeometry(80, 180, 70, 20);
	HSL2_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    HSL2_QDSpinBox.setProperty("hasNoBorderRadius", true);
	HSL3_QDSpinBox.setGeometry(80, 200, 70, 20);
	HSL3_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    HSL3_QDSpinBox.setProperty("hasBottomBorderRadius", true);
	HSV1_QDSpinBox.setGeometry(160, 160, 70, 20);
	HSV1_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    HSV1_QDSpinBox.setProperty("hasTopBorderRadius", true);
	HSV2_QDSpinBox.setGeometry(160, 180, 70, 20);
	HSV2_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    HSV2_QDSpinBox.setProperty("hasNoBorderRadius", true);
	HSV3_QDSpinBox.setGeometry(160, 200, 70, 20);
	HSV3_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
    HSV3_QDSpinBox.setProperty("hasBottomBorderRadius", true);
	LUMI_QDSpinBox.setGeometry(0, 260, 70, 20);
	LUMI_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
	INTP_QDSpinBox.setGeometry(80, 260, 70, 20);
	INTP_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
	ALPH_QDSpinBox.setEnabled(false);
	ALPH_QDSpinBox.setGeometry(160, 260, 70, 20);
	ALPH_QDSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
	Name_QLineEdit.setGeometry(240, 160, 70, 20);
	Name_QLineEdit.setAlignment(Qt::AlignmentFlag::AlignCenter);
    Name_QLineEdit.setProperty("hasTopBorderRadius", true);
	Tag_QLineEdit.setGeometry(240, 180, 70, 20);
	Tag_QLineEdit.setAlignment(Qt::AlignmentFlag::AlignCenter);
    Tag_QLineEdit.setProperty("hasNoBorderRadius", true);
	Hex_QLineEdit.setGeometry(240, 200, 70, 20);
	Hex_QLineEdit.setAlignment(Qt::AlignmentFlag::AlignCenter);
    Hex_QLineEdit.setProperty("hasBottomBorderRadius", true);

	Button_QWidget.setGeometry(10, 450, 480, 30);
	Load_QPushButton.setGeometry(0, 10, 70, 20);
	Load_QPushButton.setText("Load");
	Save_QPushButton.setGeometry(80, 10, 70, 20);
	Save_QPushButton.setText("Save");
	Reset_QPushButton.setGeometry(160, 10, 70, 20);
	Reset_QPushButton.setText("Reset");
	Invert_QPushButton.setGeometry(250, 10, 70, 20);
	Invert_QPushButton.setText("Invert");
	Empty_QPushButton.setGeometry(330, 10, 70, 20);
	Empty_QPushButton.setText("Empty");
	Random_QPushButton.setGeometry(410, 10, 70, 20);
	Random_QPushButton.setText("Random");
	QLine_3.setEnabled(false);
	QLine_3.setGeometry(0, 0, 480, 1);
	QLine_3.setFrameShadow(QFrame::Shadow::Plain);
	QLine_3.setFrameShape(QFrame::Shape::HLine);
	QLine_4.setEnabled(false);
	QLine_4.setGeometry(239, 1, 1, 28);
	QLine_4.setFrameShadow(QFrame::Shadow::Plain);
	QLine_4.setFrameShape(QFrame::Shape::VLine);

	QLineBorder_5.setGeometry(1, 30, 498, 1);
	QLineBorder_5.setFrameShadow(QFrame::Shadow::Plain);
	QLineBorder_5.setFrameShape(QFrame::Shape::HLine);

	Blocks_QWidget.setGeometry(330, 40, 160, 400);
	Slots_QWidget.setGeometry(10, 490, 480, 120);

	SlotBack_QLabel.setGeometry(260, 390, 50, 50);
	SlotBack_QLabel.setPixmap(QPixmap(":/Checker/Slot.svg"));
	Slot_QWidget.setGeometry(260, 390, 50, 50);
	Slot_QWidget.setAutoFillBackground(true);
	SlotMask_QLabel.setGeometry(260, 390, 50, 50);
	SlotMask_QLabel.setPixmap(QPixmap(":/Target/2 Big.svg"));
}