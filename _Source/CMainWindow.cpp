#include "CMainWindow.h"

#include "CDialog/CConfig.h"
#include "CGeneral/CCore.h"
#include "CGeneral/CStyle.h"
#include "CMacro/CError.h"
#include "CMacro/CSignal.h"

#include <QtCore/QDir>
#include <QtCore/QTextStream>

#include <ctime>

CMainWindow::CMainWindow() :
	CMainWindowUI()
{
	InitializeArrays();
	LinkStateStatic();
	LinkStateDynamic();

	CErrorMessageReturnQuit
    (
        QDir().mkpath(CCore::folderConfig),
	    "Error",
	    "Please Check Folder Permissions\n" + CCore::folderConfig,
        this
    )

	if (!ConfigLoad())
	{
		ConfigReset();

		CErrorMessageReturnQuit
        (
            ConfigLoad(),
		    "Error",
		    "Please Check File Permissions\n" + CCore::fileConfig,
            this
        )
	}

	srand(time(nullptr));
	switch(CConfig::startSlots)
	{
	    case CConfig::Slots::Random:
	    	State_Random_QPushButton_MouseRightReleased();
	    	break;
	    case CConfig::Slots::Empty:
	    	State_Empty_QPushButton_MouseRightReleased();
	    	break;
	    case CConfig::Slots::Custom:
            State_Empty_QPushButton_MouseRightReleased(CConfig::colorCustom);
	    	break;
	}

	Style_QWidget.setStyleSheet(CStyle::styleSheet);
}

void CMainWindow::closeEvent(QCloseEvent *__restrict__)
{
	ConfigSave();
}

const QColor CMainWindow::RandomColorRGB() const
{
	const int w = Alpha_QCheckBox.isChecked() ? CCore::RandomPInt(WMin_QDSpinBox.Result(), WMax_QDSpinBox.Result(), WMax_QDSpinBox.Limit() + 1) : 255;
	const int x = CCore::RandomPInt(XMin_QDSpinBox.Result(), XMax_QDSpinBox.Result(), XMax_QDSpinBox.Limit() + 1);
	const int y = CCore::RandomPInt(YMin_QDSpinBox.Result(), YMax_QDSpinBox.Result(), YMax_QDSpinBox.Limit() + 1);
	const int z = CCore::RandomPInt(ZMin_QDSpinBox.Result(), ZMax_QDSpinBox.Result(), ZMax_QDSpinBox.Limit() + 1);

	return QColor::fromRgb(x, y, z, w);
}

const QColor CMainWindow::RandomColorGRY() const
{
	const int w = Alpha_QCheckBox.isChecked() ? CCore::RandomPInt(WMin_QDSpinBox.Result(), WMax_QDSpinBox.Result(), WMax_QDSpinBox.Limit() + 1) : 255;
	const int x = CCore::RandomPInt(XMin_QDSpinBox.Result(), XMax_QDSpinBox.Result(), XMax_QDSpinBox.Limit() + 1);

	return QColor::fromRgb(x, x, x, w);
}

const QColor CMainWindow::RandomColorHSL() const
{
	const int w = Alpha_QCheckBox.isChecked() ? CCore::RandomPInt(WMin_QDSpinBox.Result(), WMax_QDSpinBox.Result(), WMax_QDSpinBox.Limit() + 1) : 255;
	const int x = CCore::RandomPInt(XMin_QDSpinBox.Result(), XMax_QDSpinBox.Result(), XMax_QDSpinBox.Limit() + 1);
	const int y = CCore::RandomPInt(YMin_QDSpinBox.Result(), YMax_QDSpinBox.Result(), YMax_QDSpinBox.Limit() + 1);
	const int z = CCore::RandomPInt(ZMin_QDSpinBox.Result(), ZMax_QDSpinBox.Result(), ZMax_QDSpinBox.Limit() + 1);

	return QColor::fromHsl(x, y, z, w);
}

const QColor CMainWindow::RandomColorHSV() const
{
	const int w = Alpha_QCheckBox.isChecked() ? CCore::RandomPInt(WMin_QDSpinBox.Result(), WMax_QDSpinBox.Result(), WMax_QDSpinBox.Limit() + 1) : 255;
	const int x = CCore::RandomPInt(XMin_QDSpinBox.Result(), XMax_QDSpinBox.Result(), XMax_QDSpinBox.Limit() + 1);
	const int y = CCore::RandomPInt(YMin_QDSpinBox.Result(), YMax_QDSpinBox.Result(), YMax_QDSpinBox.Limit() + 1);
	const int z = CCore::RandomPInt(ZMin_QDSpinBox.Result(), ZMax_QDSpinBox.Result(), ZMax_QDSpinBox.Limit() + 1);

	return QColor::fromHsv(x, y, z, w);
}

void CMainWindow::RefreshAll(const QColor &__restrict__ color)
{
	CWidget_Slot::Selected()->SetColor(color);
	RefreshAll();
}

void CMainWindow::RefreshAll()
{
	RGB1_QDSpinBox.SetResult(CWidget_Slot::Selected()->Rgb1());
	RGB2_QDSpinBox.SetResult(CWidget_Slot::Selected()->Rgb2());
	RGB3_QDSpinBox.SetResult(CWidget_Slot::Selected()->Rgb3());

	HSL1_QDSpinBox.SetResult(CWidget_Slot::Selected()->Hsl1());
	HSL2_QDSpinBox.SetResult(CWidget_Slot::Selected()->Hsl2());
	HSL3_QDSpinBox.SetResult(CWidget_Slot::Selected()->Hsl3());

	HSV1_QDSpinBox.SetResult(CWidget_Slot::Selected()->Hsv1());
	HSV2_QDSpinBox.SetResult(CWidget_Slot::Selected()->Hsv2());
	HSV3_QDSpinBox.SetResult(CWidget_Slot::Selected()->Hsv3());

	LUMI_QDSpinBox.SetResult(CWidget_Slot::Selected()->Lumi());
	INTP_QDSpinBox.SetResult(CWidget_Slot::Selected()->Intp());

	Name_QLineEdit.setText(CWidget_Slot::Selected()->name);
	Tag_QLineEdit.setText(CWidget_Slot::Selected()->tag);
	jump RefreshHex();

	jump RefreshBlock();

	Slot_QWidget.setPalette(CWidget_Slot::Selected()->Color());
}

void CMainWindow::RefreshHex3()
{
	const QString r(QString("%1").arg(CWidget_Slot::Selected()->Rgb1(), 2, 16, QLatin1Char('0')));
	const QString g(QString("%1").arg(CWidget_Slot::Selected()->Rgb2(), 2, 16, QLatin1Char('0')));
	const QString b(QString("%1").arg(CWidget_Slot::Selected()->Rgb3(), 2, 16, QLatin1Char('0')));

	Hex_QLineEdit.setText('#' + r + g + b);
}

void CMainWindow::RefreshHex4RGBA()
{
	const QString r(QString("%1").arg(CWidget_Slot::Selected()->Rgb1(), 2, 16, QLatin1Char('0')));
	const QString g(QString("%1").arg(CWidget_Slot::Selected()->Rgb2(), 2, 16, QLatin1Char('0')));
	const QString b(QString("%1").arg(CWidget_Slot::Selected()->Rgb3(), 2, 16, QLatin1Char('0')));
	const QString a(QString("%1").arg(CWidget_Slot::Selected()->Alph(), 2, 16, QLatin1Char('0')));

	Hex_QLineEdit.setText('#' + r + g + b + a);
}

void CMainWindow::RefreshHex4ARGB()
{
	const QString r(QString("%1").arg(CWidget_Slot::Selected()->Rgb1(), 2, 16, QLatin1Char('0')));
	const QString g(QString("%1").arg(CWidget_Slot::Selected()->Rgb2(), 2, 16, QLatin1Char('0')));
	const QString b(QString("%1").arg(CWidget_Slot::Selected()->Rgb3(), 2, 16, QLatin1Char('0')));
	const QString a(QString("%1").arg(CWidget_Slot::Selected()->Alph(), 2, 16, QLatin1Char('0')));

	Hex_QLineEdit.setText('#' + a + r + g + b);
}

void CMainWindow::RefreshBlock3RGB()
{
	Blocks_QWidget.XBlock_QWidget.SetGradient
    (
		QColor::fromRgb
        (
			255,
			CWidget_Slot::Selected()->Rgb2(),
			CWidget_Slot::Selected()->Rgb3()
		),
		QColor::fromRgb
        (
			0,
			CWidget_Slot::Selected()->Rgb2(),
			CWidget_Slot::Selected()->Rgb3()
		)
	);
	Blocks_QWidget.YBlock_QWidget.SetGradient
    (
		QColor::fromRgb
        (
			CWidget_Slot::Selected()->Rgb1(),
			255,
			CWidget_Slot::Selected()->Rgb3()
		),
		QColor::fromRgb
        (
			CWidget_Slot::Selected()->Rgb1(),
			0,
			CWidget_Slot::Selected()->Rgb3()
		)
	);
	Blocks_QWidget.ZBlock_QWidget.SetGradient
    (
		QColor::fromRgb
        (
			CWidget_Slot::Selected()->Rgb1(),
			CWidget_Slot::Selected()->Rgb2(),
			255
		),
		QColor::fromRgb
        (
			CWidget_Slot::Selected()->Rgb1(),
			CWidget_Slot::Selected()->Rgb2(),
			0
		)
	);

	Blocks_QWidget.XBlock_QWidget.SetResult(CWidget_Slot::Selected()->Rgb1(), CWidget_Slot::Selected()->Lumi());
	Blocks_QWidget.YBlock_QWidget.SetResult(CWidget_Slot::Selected()->Rgb2(), CWidget_Slot::Selected()->Lumi());
	Blocks_QWidget.ZBlock_QWidget.SetResult(CWidget_Slot::Selected()->Rgb3(), CWidget_Slot::Selected()->Lumi());
}

void CMainWindow::RefreshBlock3GRY()
{
	Blocks_QWidget.XBlock_QWidget.SetGradient
    (
		QColor::fromRgb
        (
			255,
			255,
			255
		),
		QColor::fromRgb
        (
			0,
			0,
			0
		)
	);
	Blocks_QWidget.YBlock_QWidget.SetGradient
    (
		QColor::fromRgb
        (
			255,
			255,
			255
		),
		QColor::fromRgb
        (
			0,
			0,
			0
		)
	);
	Blocks_QWidget.ZBlock_QWidget.SetGradient
    (
		QColor::fromRgb
        (
			255,
			255,
			255
		),
		QColor::fromRgb
        (
			0,
			0,
			0
		)
	);

	Blocks_QWidget.XBlock_QWidget.SetResult(CWidget_Slot::Selected()->Rgb1(), CWidget_Slot::Selected()->Lumi());
	Blocks_QWidget.YBlock_QWidget.SetResult(CWidget_Slot::Selected()->Rgb2(), CWidget_Slot::Selected()->Lumi());
	Blocks_QWidget.ZBlock_QWidget.SetResult(CWidget_Slot::Selected()->Rgb3(), CWidget_Slot::Selected()->Lumi());
}

void CMainWindow::RefreshBlock3HSL()
{
	Blocks_QWidget.XBlock_QWidget.SetGradientHSL
    (
		CWidget_Slot::Selected()->Hsl2(),
		CWidget_Slot::Selected()->Hsl3()
	);
	Blocks_QWidget.YBlock_QWidget.SetGradient
    (
		QColor::fromHsl
        (
			CWidget_Slot::Selected()->Hsl1(),
			255,
			CWidget_Slot::Selected()->Hsl3()
		),
		QColor::fromHsl
        (
			CWidget_Slot::Selected()->Hsl1(),
			0,
			CWidget_Slot::Selected()->Hsl3()
		)
	);
	Blocks_QWidget.ZBlock_QWidget.SetGradient
    (
		QColor::fromHsl
        (
			CWidget_Slot::Selected()->Hsl1(),
			CWidget_Slot::Selected()->Hsl2(),
			255
		),
		QColor::fromHsl
        (
			CWidget_Slot::Selected()->Hsl1(),
			CWidget_Slot::Selected()->Hsl2(),
			128
		),
		QColor::fromHsl
        (
			CWidget_Slot::Selected()->Hsl1(),
			CWidget_Slot::Selected()->Hsl2(),
			0
		)
	);

	Blocks_QWidget.XBlock_QWidget.SetResult(CWidget_Slot::Selected()->Hsl1(), CWidget_Slot::Selected()->Lumi());
	Blocks_QWidget.YBlock_QWidget.SetResult(CWidget_Slot::Selected()->Hsl2(), CWidget_Slot::Selected()->Lumi());
	Blocks_QWidget.ZBlock_QWidget.SetResult(CWidget_Slot::Selected()->Hsl3(), CWidget_Slot::Selected()->Lumi());
}

void CMainWindow::RefreshBlock3HSV()
{
	Blocks_QWidget.XBlock_QWidget.SetGradientHSV
    (
		CWidget_Slot::Selected()->Hsv2(),
		CWidget_Slot::Selected()->Hsv3()
	);
	Blocks_QWidget.YBlock_QWidget.SetGradient
    (
		QColor::fromHsv
        (
			CWidget_Slot::Selected()->Hsv1(),
			255,
			CWidget_Slot::Selected()->Hsv3()
		),
		QColor::fromHsv
        (
			CWidget_Slot::Selected()->Hsv1(),
			0,
			CWidget_Slot::Selected()->Hsv3()
		)
	);
	Blocks_QWidget.ZBlock_QWidget.SetGradient
    (
		QColor::fromHsv
        (
			CWidget_Slot::Selected()->Hsv1(),
			CWidget_Slot::Selected()->Hsv2(),
			255
		),
		QColor::fromHsv
        (
			CWidget_Slot::Selected()->Hsv1(),
			CWidget_Slot::Selected()->Hsv2(),
			0
		)
	);

	Blocks_QWidget.XBlock_QWidget.SetResult(CWidget_Slot::Selected()->Hsv1(), CWidget_Slot::Selected()->Lumi());
	Blocks_QWidget.YBlock_QWidget.SetResult(CWidget_Slot::Selected()->Hsv2(), CWidget_Slot::Selected()->Lumi());
	Blocks_QWidget.ZBlock_QWidget.SetResult(CWidget_Slot::Selected()->Hsv3(), CWidget_Slot::Selected()->Lumi());
}

void CMainWindow::RefreshBlock4()
{
	ALPH_QDSpinBox.SetResult(CWidget_Slot::Selected()->Alph());

	Blocks_QWidget.WBlock_QWidget.SetGradient
    (
		QColor::fromRgb
        (
			CWidget_Slot::Selected()->Rgb1(),
			CWidget_Slot::Selected()->Rgb2(),
			CWidget_Slot::Selected()->Rgb3(),
			255
		),
		QColor::fromRgb
        (
			CWidget_Slot::Selected()->Rgb1(),
			CWidget_Slot::Selected()->Rgb2(),
			CWidget_Slot::Selected()->Rgb3(),
			0
		)
	);

	Blocks_QWidget.WBlock_QWidget.SetResult(CWidget_Slot::Selected()->Alph(), CWidget_Slot::Selected()->Lumi());
}

void CMainWindow::RefreshSpinBoxState()
{
	XMin_QDSpinBox.RefreshState();
	XMax_QDSpinBox.RefreshState();
	YMin_QDSpinBox.RefreshState();
	YMax_QDSpinBox.RefreshState();
	ZMin_QDSpinBox.RefreshState();
	ZMax_QDSpinBox.RefreshState();
	WMin_QDSpinBox.RefreshState();
	WMax_QDSpinBox.RefreshState();

	RGB1_QDSpinBox.RefreshState();
	RGB2_QDSpinBox.RefreshState();
	RGB3_QDSpinBox.RefreshState();
	HSL1_QDSpinBox.RefreshState();
	HSL2_QDSpinBox.RefreshState();
	HSL3_QDSpinBox.RefreshState();
	HSV1_QDSpinBox.RefreshState();
	HSV2_QDSpinBox.RefreshState();
	HSV3_QDSpinBox.RefreshState();
	LUMI_QDSpinBox.RefreshState();
	INTP_QDSpinBox.RefreshState();
	ALPH_QDSpinBox.RefreshState();
}