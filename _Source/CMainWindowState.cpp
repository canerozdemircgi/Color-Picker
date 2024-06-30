#include "CMainWindow.h"

#include "CDialog/CConfig.h"
#include "CGeneral/CCore.h"
#include "CMacro/CError.h"
#include "CMacro/CSignal.h"
#include "CMenu/CMenu_Main.h"

#include <QtCore/QTextStream>
#include <QtWidgets/QFileDialog>

void CMainWindow::State_RGB_QRadioButton_Toggled()
{
	if (RGB_QRadioButton.isChecked())
	{
		CRadioButton_Mode::indexSelected = RGB_QRadioButton.index;

		X_QLabel.setText("Space R");
		Y_QLabel.setText("Space G");
		Z_QLabel.setText("Space B");

		Alpha_QComboBox.setItemText(0, "RGBA");
		Alpha_QComboBox.setItemText(1, "ARGB");

		XMin_QDSpinBox.SetLimit(-255, 255);
		XMax_QDSpinBox.SetLimit(-255, 255);
		XMin_QDSpinBox.SetResult(-255);
		XMax_QDSpinBox.SetResult(255);

		Blocks_QWidget.XBlock_QWidget.limit = 255;

		RandomColor = std::bind(&CMainWindow::RandomColorRGB, this);
		ALPH_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_ALPH_RGB_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		if (Alpha_QCheckBox.isChecked())
			RefreshBlock = [this]() { RefreshBlock3RGB(); RefreshBlock4(); };
		else
			RefreshBlock = std::bind(&CMainWindow::RefreshBlock3RGB, this);
		jump RefreshBlock();

		Blocks_QWidget.XBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_RGB1_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		Blocks_QWidget.YBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_RGB2_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		Blocks_QWidget.ZBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_RGB3_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	}
}

void CMainWindow::State_GRY_QRadioButton_Toggled()
{
	if (GRY_QRadioButton.isChecked())
	{
		CRadioButton_Mode::indexSelected = GRY_QRadioButton.index;

		X_QLabel.setText("Space G");
		Y_QLabel.setText("Space G");
		Z_QLabel.setText("Space G");

		Alpha_QComboBox.setItemText(0, "GGGA");
		Alpha_QComboBox.setItemText(1, "AGGG");

		XMin_QDSpinBox.SetLimit(-255, 255);
		XMax_QDSpinBox.SetLimit(-255, 255);
		XMin_QDSpinBox.SetResult(-255);
		XMax_QDSpinBox.SetResult(255);

		Blocks_QWidget.XBlock_QWidget.limit = 255;

		RandomColor = std::bind(&CMainWindow::RandomColorGRY, this);
		ALPH_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_ALPH_GRY_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		if (Alpha_QCheckBox.isChecked())
			RefreshBlock = [this]() { RefreshBlock3GRY(); RefreshBlock4(); };
		else
			RefreshBlock = std::bind(&CMainWindow::RefreshBlock3GRY, this);
		jump RefreshBlock();

		Blocks_QWidget.XBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_INTP_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		Blocks_QWidget.YBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_INTP_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		Blocks_QWidget.ZBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_INTP_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);

		Y_QLabel.setEnabled(false);
		YMin_QDSpinBox.setEnabled(false);
		YMax_QDSpinBox.setEnabled(false);
		Z_QLabel.setEnabled(false);
		ZMin_QDSpinBox.setEnabled(false);
		ZMax_QDSpinBox.setEnabled(false);
	}
	else
	{
		Y_QLabel.setEnabled(true);
		YMin_QDSpinBox.setEnabled(true);
		YMax_QDSpinBox.setEnabled(true);
		Z_QLabel.setEnabled(true);
		ZMin_QDSpinBox.setEnabled(true);
		ZMax_QDSpinBox.setEnabled(true);
	}
}

void CMainWindow::State_HSL_QRadioButton_Toggled()
{
	if (HSL_QRadioButton.isChecked())
	{
		CRadioButton_Mode::indexSelected = HSL_QRadioButton.index;

		X_QLabel.setText("Space H");
		Y_QLabel.setText("Space S");
		Z_QLabel.setText("Space L");

		Alpha_QComboBox.setItemText(0, "HSLA");
		Alpha_QComboBox.setItemText(1, "AHSL");

		XMin_QDSpinBox.SetLimit(-359, 359);
		XMax_QDSpinBox.SetLimit(-359, 359);
		XMin_QDSpinBox.SetResult(-359);
		XMax_QDSpinBox.SetResult(359);

		Blocks_QWidget.XBlock_QWidget.limit = 359;

		RandomColor = std::bind(&CMainWindow::RandomColorHSL, this);
		ALPH_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_ALPH_HSL_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		if (Alpha_QCheckBox.isChecked())
			RefreshBlock = [this]() { RefreshBlock3HSL(); RefreshBlock4(); };
		else
			RefreshBlock = std::bind(&CMainWindow::RefreshBlock3HSL, this);
		jump RefreshBlock();

		Blocks_QWidget.XBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_HSL1_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		Blocks_QWidget.YBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_HSL2_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		Blocks_QWidget.ZBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_HSL3_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	}
}

void CMainWindow::State_HSV_QRadioButton_Toggled()
{
	if (HSV_QRadioButton.isChecked())
	{
		CRadioButton_Mode::indexSelected = HSV_QRadioButton.index;

		X_QLabel.setText("Space H");
		Y_QLabel.setText("Space S");
		Z_QLabel.setText("Space V");

		Alpha_QComboBox.setItemText(0, "HSVA");
		Alpha_QComboBox.setItemText(1, "AHSV");

		XMin_QDSpinBox.SetLimit(-359, 359);
		XMax_QDSpinBox.SetLimit(-359, 359);
		XMin_QDSpinBox.SetResult(-359);
		XMax_QDSpinBox.SetResult(359);

		Blocks_QWidget.XBlock_QWidget.limit = 359;

		RandomColor = std::bind(&CMainWindow::RandomColorHSV, this);
		ALPH_QDSpinBox.ValueChangedNotBySet = std::bind(&CMainWindow::State_ALPH_HSV_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		if (Alpha_QCheckBox.isChecked())
			RefreshBlock = [this]() { RefreshBlock3HSV(); RefreshBlock4(); };
		else
			RefreshBlock = std::bind(&CMainWindow::RefreshBlock3HSV, this);
		jump RefreshBlock();

		Blocks_QWidget.XBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_HSV1_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		Blocks_QWidget.YBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_HSV2_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
		Blocks_QWidget.ZBlock_QWidget.MouseMoved = std::bind(&CMainWindow::State_HSV3_QDSpinBox_ValueChangedNotBySet, this, std::placeholders::_1);
	}
}

void CMainWindow::State_Alpha_QCheckBox_toggled(const bool checked)
{
	W_QLabel.setEnabled(checked);
	WMin_QDSpinBox.setEnabled(checked);
	WMax_QDSpinBox.setEnabled(checked);

	Alpha_QComboBox.setEnabled(checked);

	ALP_QLabel.setEnabled(checked);
	ALPH_QDSpinBox.setEnabled(checked);

	Blocks_QWidget.WBlock_QWidget.SetEnabled(checked);

	if (checked)
	{
		State_Alpha_QComboBox_currentIndexChanged(Alpha_QComboBox.currentIndex());

		if (RGB_QRadioButton.isChecked())
			RefreshBlock = [this]() { RefreshBlock3RGB(); RefreshBlock4(); };
		else if (GRY_QRadioButton.isChecked())
			RefreshBlock = [this]() { RefreshBlock3GRY(); RefreshBlock4(); };
		else if (HSL_QRadioButton.isChecked())
			RefreshBlock = [this]() { RefreshBlock3HSL(); RefreshBlock4(); };
		else if (HSV_QRadioButton.isChecked())
			RefreshBlock = [this]() { RefreshBlock3HSV(); RefreshBlock4(); };
	}
	else
	{
		RefreshHex = std::bind(&CMainWindow::RefreshHex3, this);
		jump RefreshHex();

		if (RGB_QRadioButton.isChecked())
			RefreshBlock = std::bind(&CMainWindow::RefreshBlock3RGB, this);
		else if (GRY_QRadioButton.isChecked())
			RefreshBlock = std::bind(&CMainWindow::RefreshBlock3GRY, this);
		else if (HSL_QRadioButton.isChecked())
			RefreshBlock = std::bind(&CMainWindow::RefreshBlock3HSL, this);
		else if (HSV_QRadioButton.isChecked())
			RefreshBlock = std::bind(&CMainWindow::RefreshBlock3HSV, this);
	}
	ALPH_QDSpinBox.ValueChangedNotBySet(ALPH_QDSpinBox.Limit());
}

void CMainWindow::State_Alpha_QComboBox_currentIndexChanged(const int index)
{
	RefreshHex = index ? std::bind(&CMainWindow::RefreshHex4ARGB, this) : std::bind(&CMainWindow::RefreshHex4RGBA, this);
	jump RefreshHex();
}

void CMainWindow::State_Float_QCheckBox_toggled(const bool checked)
{
	Gamma_QCheckBox.setEnabled(checked);
	Gamma_QDSpinBox.setEnabled(Gamma_QCheckBox.isChecked());

	CDoubleSpinBox::stateDouble = checked;
	State_FloatPrec_QSpinBox_valueChanged(CDoubleSpinBox::precision);
}

void CMainWindow::State_FloatPrec_QSpinBox_valueChanged(const int value)
{
	Gamma_QDSpinBox.setDecimals(value);
	MagnifyRat_QDSpinBox.setDecimals(value);

	CDoubleSpinBox::precision = value;
	RefreshSpinBoxState();
}

void CMainWindow::State_Gamma_QCheckBox_toggled(const bool checked)
{
	Gamma_QDSpinBox.setEnabled(checked);

	CDoubleSpinBox::stateGamma = checked;
	State_Gamma_QDSpinBox_valueChanged(Gamma_QDSpinBox.value());
}

void CMainWindow::State_Gamma_QDSpinBox_valueChanged(const double value)
{
	CDoubleSpinBox::gamma = value;
	RefreshSpinBoxState();
}

void CMainWindow::State_Empty_QPushButton_MouseLeftReleased()
{
	const QColor colorEmpty(QColor(CConfig::colorEmpty));
	CWidget_Slot::Selected()->SetColor(colorEmpty);
	RefreshAll();
}

void CMainWindow::State_Empty_QPushButton_MouseRightReleased()
{
	const QColor colorEmpty(QColor(CConfig::colorEmpty));
	for (int i = 0; i < slotSize; ++i)
		slot[i]->SetColor(colorEmpty);
	RefreshAll();
}

void CMainWindow::State_Random_QPushButton_MouseLeftReleased()
{
	CWidget_Slot::Selected()->SetColor(jump RandomColor());
	RefreshAll();
}

void CMainWindow::State_Random_QPushButton_MouseRightReleased()
{
	for (int i = 0; i < slotSize; ++i)
		slot[i]->SetColor(jump RandomColor());
	RefreshAll();
}

void CMainWindow::State_Random_QPushButton_MouseMiddleReleased()
{
	slot[CCore::RandomInt(0, slotSize - 1)]->SetSelected();
	RefreshAll();
}

void CMainWindow::State_Slot_MouseWheeled(const int delta)
{
	slot[(CWidget_Slot::Selected()->index + delta + slotSize) % slotSize]->SetSelected();
	RefreshAll();
}

void CMainWindow::State_Invert_QPushButton_MouseLeftReleased()
{
	CWidget_Slot::Selected()->SetColor(QColor::fromRgb
    (
		~CWidget_Slot::Selected()->Rgb1() & 0xff,
		~CWidget_Slot::Selected()->Rgb2() & 0xff,
		~CWidget_Slot::Selected()->Rgb3() & 0xff,
		CWidget_Slot::Selected()->Alph()
	));
	RefreshAll();
}

void CMainWindow::State_Invert_QPushButton_MouseRightReleased()
{
	for (int i = 0; i < slotSize; ++i)
	{
		slot[i]->SetColor(QColor::fromRgb
        (
			~slot[i]->Rgb1() & 0xff,
			~slot[i]->Rgb2() & 0xff,
			~slot[i]->Rgb3() & 0xff,
			slot[i]->Alph()
		));
	}
	RefreshAll();
}

void CMainWindow::State_Pick_QPushButton_MouseMiddlePressed()
{
	slot[(CWidget_Slot::Selected()->index - 1 + slotSize) % slotSize]->SetSelected();
    State_Pick_QPushButton_MouseLeftPressed();
}

void CMainWindow::State_Pick_QPushButton_MouseRightPressed()
{
	slot[(CWidget_Slot::Selected()->index + 1) % slotSize]->SetSelected();
    State_Pick_QPushButton_MouseLeftPressed();
}

void CMainWindow::State_Pick_QPushButton_MouseLeftPressed()
{
	magnifier = new CMagnifier
    (
		MagnifyInvert_QCheckBox.isChecked(),
		MagnifyRat_QDSpinBox.value(),
		MagnifyResX_QSpinBox.value(),
		MagnifyResY_QSpinBox.value(),
		MagnifyQuality_QComboBox.currentData().value<cv::InterpolationFlags>(),
		std::bind(&CMainWindow::State_Magnifier_MouseRightPressed, this),
		std::bind(&CMainWindow::State_Magnifier_MouseMiddlePressed, this),
		std::bind(&CMainWindow::State_Magnifier_MouseMoved, this, std::placeholders::_1, std::placeholders::_2),
		std::bind(&CMainWindow::State_Magnifier_MouseWheeled, this, std::placeholders::_1)
	);
}

void CMainWindow::State_Pick_QPushButton_MouseMoved()
{
	magnifier->MouseMove(QCursor::pos().x(), QCursor::pos().y());
}

void CMainWindow::State_Pick_QPushButton_MouseReleased()
{
    magnifier->MouseRelease();
}

void CMainWindow::State_Magnifier_MouseMoved(const QColor &__restrict__ pick, const QString &__restrict__ coord)
{
	RefreshAll(pick);
	Pick_QPushButton.setText(coord);
}

cv::InterpolationFlags CMainWindow::State_Magnifier_MouseRightPressed()
{
	MagnifyQuality_QComboBox.setCurrentIndex((MagnifyQuality_QComboBox.currentIndex() + 1) % MagnifyQuality_QComboBox.count());
	return MagnifyQuality_QComboBox.currentData().value<cv::InterpolationFlags>();
}

bool CMainWindow::State_Magnifier_MouseMiddlePressed()
{
	MagnifyInvert_QCheckBox.toggle();
	return MagnifyInvert_QCheckBox.isChecked();
}

void CMainWindow::State_Magnifier_MouseWheeled(const double magRatio)
{
	MagnifyRat_QDSpinBox.setValue(magRatio);
}

void CMainWindow::State_RGB1_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromRgb
    (
		value,
		CWidget_Slot::Selected()->Rgb2(),
		CWidget_Slot::Selected()->Rgb3(),
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_RGB2_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromRgb
    (
		CWidget_Slot::Selected()->Rgb1(),
		value,
		CWidget_Slot::Selected()->Rgb3(),
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_RGB3_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromRgb
    (
		CWidget_Slot::Selected()->Rgb1(),
		CWidget_Slot::Selected()->Rgb2(),
		value,
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_HSL1_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromHsl
    (
		value,
		CWidget_Slot::Selected()->Hsl2(),
		CWidget_Slot::Selected()->Hsl3(),
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_HSL2_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromHsl
    (
		CWidget_Slot::Selected()->Hsl1(),
		value,
		CWidget_Slot::Selected()->Hsl3(),
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_HSL3_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromHsl
    (
		CWidget_Slot::Selected()->Hsl1(),
		CWidget_Slot::Selected()->Hsl2(),
		value,
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_HSV1_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromHsv
    (
		value,
		CWidget_Slot::Selected()->Hsv2(),
		CWidget_Slot::Selected()->Hsv3(),
		CWidget_Slot::Selected()->Alph()
	));

}

void CMainWindow::State_HSV2_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromHsv
    (
		CWidget_Slot::Selected()->Hsv1(),
		value,
		CWidget_Slot::Selected()->Hsv3(),
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_HSV3_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromHsv
    (
		CWidget_Slot::Selected()->Hsv1(),
		CWidget_Slot::Selected()->Hsv2(),
		value,
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_LUMI_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromRgb
    (
		value,
		value,
		value,
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_INTP_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromRgb
    (
		value,
		value,
		value,
		CWidget_Slot::Selected()->Alph()
	));
}

void CMainWindow::State_ALPH_RGB_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromRgb
    (
		CWidget_Slot::Selected()->Rgb1(),
		CWidget_Slot::Selected()->Rgb2(),
		CWidget_Slot::Selected()->Rgb3(),
		value
	));
}

void CMainWindow::State_ALPH_GRY_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromRgb
    (
		CWidget_Slot::Selected()->Rgb1(),
		CWidget_Slot::Selected()->Rgb2(),
		CWidget_Slot::Selected()->Rgb3(),
		value
	));
}

void CMainWindow::State_ALPH_HSL_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromHsl
    (
		CWidget_Slot::Selected()->Hsl1(),
		CWidget_Slot::Selected()->Hsl2(),
		CWidget_Slot::Selected()->Hsl3(),
		value
	));
}

void CMainWindow::State_ALPH_HSV_QDSpinBox_ValueChangedNotBySet(const int value)
{
	RefreshAll(QColor::fromHsv
    (
		CWidget_Slot::Selected()->Hsv1(),
		CWidget_Slot::Selected()->Hsv2(),
		CWidget_Slot::Selected()->Hsv3(),
		value
	));
}

void CMainWindow::State_Name_QLineEdit_textEdited(const QString &__restrict__ arg)
{
	CWidget_Slot::Selected()->name = arg;
}

void CMainWindow::State_Tag_QLineEdit_textEdited(const QString &__restrict__ arg)
{
	CWidget_Slot::Selected()->tag = arg;
}

void CMainWindow::State_Hex_QLineEdit_returnPressed()
{
	const QString hexadecimal(Hex_QLineEdit.text()[0] == '#' ? Hex_QLineEdit.text() : '#' + Hex_QLineEdit.text());
	const QColor result(hexadecimal);

	if (result.isValid())
	{
		if (Alpha_QCheckBox.isChecked())
		{
			if (Alpha_QComboBox.currentIndex() == 0)
				RefreshAll(QColor('#' + hexadecimal.mid(7, 2) + hexadecimal.mid(1, 6)));
			else if (Alpha_QComboBox.currentIndex() == 1)
				RefreshAll(result);
		}
		else
			RefreshAll(result);
	}
	else
		new CMessage
        (
			"Warning",
			"Wrong Hexadecimal Value, Try Again",
            this
		);
}

void CMainWindow::State_Load_QPushButton_MouseLeftReleased()
{
	const QString fileName(QFileDialog::getOpenFileName(this, "Color File Load", nullptr, "Color Files (*.clr)"));
	if (fileName != nullptr)
		Load_QPushButton_MouseLeftReleased(fileName);
}

void CMainWindow::Load_QPushButton_MouseLeftReleased(const QString &__restrict__ fileName)
{
	QFile colorLoad(fileName);
	if (colorLoad.open(QIODevice::OpenModeFlag::ReadOnly))
	{
		QTextStream stream(&colorLoad);
		stream.setEncoding(QStringConverter::Utf8);

		bool ok;

		const QList<QString> lines(CCore::SeparateQString(stream.readAll(), '\n', 64, &ok));
		colorLoad.close();
		CErrorMessageReturnVoid
        (
            ok,
		    "Error",
		    "Corrupted or Incompatible File\n" + fileName,
            this
        );

		int l = -1;
		int r, g, b, a;
		for (int i = 0; i < slotSize; ++i)
		{
			const QList<QString> line(CCore::SeparateQString(lines[++l], ',', 6, &ok));
			CErrorMessageReturnVoid
            (
                ok,
			    "Error",
			    "Corrupted or Incompatible File\n" + fileName,
                this
            );

			r = line[0].toInt(&ok);
			CErrorMessageReturnVoid
            (
                ok,
			    "Error",
			    "Corrupted or Incompatible File\n" + fileName,
                this
            );
			g = line[1].toInt(&ok);
			CErrorMessageReturnVoid
            (
                ok,
			    "Error",
			    "Corrupted or Incompatible File\n" + fileName,
                this
            );
			b = line[2].toInt(&ok);
			CErrorMessageReturnVoid
            (
                ok,
			    "Error",
			    "Corrupted or Incompatible File\n" + fileName,
                this
            );
			a = line[3].toInt(&ok);
			CErrorMessageReturnVoid
            (
                ok,
			    "Error",
			    "Corrupted or Incompatible File\n" + fileName,
                this
            );

			slot[i]->SetColor(QColor::fromRgb(r, g, b, a));
			slot[i]->name = line[4];
			slot[i]->tag = line[5];
		}
		RefreshAll();
		new CMessage
        (
			"Success",
			"Colors Have Been Loaded\n" + fileName,
            this
		);
	}
	else
    {
		new CMessage
        (
			"Error",
			"Please Check File Permissions\n" + fileName,
            this
		);
    }
}

void CMainWindow::State_Save_QPushButton_MouseLeftReleased()
{
	const QString fileName(QFileDialog::getSaveFileName(this, "Color File Save", nullptr, "Color Files (*.clr)"));
	if (fileName == nullptr)
		return;

	QFile colorSave(fileName);
	if (colorSave.open(QIODevice::OpenModeFlag::WriteOnly))
	{
		QTextStream stream(&colorSave);
		stream.setEncoding(QStringConverter::Utf8);

		const int max = slotSize - 1;
		for (int i = 0; i < max; ++i)
			stream
				<< slot[i]->Rgb1() << ','
				<< slot[i]->Rgb2() << ','
				<< slot[i]->Rgb3() << ','
				<< slot[i]->Alph() << ','
				<< slot[i]->name << ','
				<< slot[i]->tag << Qt::endl;

		stream
			<< slot[max]->Rgb1() << ','
			<< slot[max]->Rgb2() << ','
			<< slot[max]->Rgb3() << ','
			<< slot[max]->Alph() << ','
			<< slot[max]->name << ','
			<< slot[max]->tag;

		colorSave.close();
		new CMessage
        (
			"Success",
			"Colors Have Been Saved\n" + fileName,
            this
		);
	}
	else
    {
		new CMessage
        (
			"Error",
			"Please Check File Permissions\n" + fileName,
            this
		);
    }
}

void CMainWindow::State_Reset_QPushButton_MouseLeftReleased()
{
	ConfigReset();
	ConfigLoad();
	RefreshAll();
}

void CMainWindow::State_Reset_QPushButton_MouseRightReleased()
{
	ConfigReset();
	ConfigLoad();
	State_Random_QPushButton_MouseRightReleased();
}

void CMainWindow::State_Icon_QPushButton_MouseLeftReleased()
{
	Title_QMenu.Show(Icon_QPushButton.mapToGlobal(QPoint(Icon_QPushButton.x() - 4, Icon_QPushButton.y() + Icon_QPushButton.height() - 1)));
}

void CMainWindow::State_Config_QAction_triggered()
{
	new CConfig(std::bind(&CMainWindow::State_FloatPrec_QSpinBox_valueChanged, this, std::placeholders::_1), this);
}

void CMainWindow::State_Help_QAction_triggered() const
{
	new CMessage
    (
		"Color-Picker Help",
		"Right-Click on the Pick button to select next slot before picking.\n"
		"Middle-Click on the Pick button to select previous slot before picking.\n"
		"\n"
		"Right-Click on the Random button to randomize all slots.\n"
		"Middle-Click on the Random button to select a random slot.\n"
		"\n"
		"Right-Click on the Empty button to empty all slots.\n"
		"Right-Click on the Invert button to invert all slots.\n"
		"\n"
		"Mouse-Wheel on the color slot area to switch between quickly.\n"
		"Mouse-Wheel on input widgets to change variables quickly.\n"
		"\n"
		"Right-Click while magnifying to change interpolation algorithm in motion.\n"
		"Mouse-Wheel while magnifying to change zoom ratio in motion.",
        this
	);
}

void CMainWindow::State_About_QAction_triggered() const
{
	new CMessage
    (
		"About",
		"Current Version : 1.2.3\n"
		"License : LGPLv3+\n"
		"\n"
		"Caner Özdemir\n"
		"canerozdemir.mail@gmail.com",
        this
	);
}

void CMainWindow::State_Simple_QPushButton_toggled(const bool checked)
{
	if (checked)
	{
		Space_QWidget.setVisible(false);
		Button_QWidget.setVisible(false);
		Blocks_QWidget.setVisible(false);
		Slots_QWidget.setVisible(false);

		Simple_QPushButton.move(193, 2);
		ATop_QPushButton.move(227, 2);
		Minimize_QPushButton.move(261, 2);
		Close_QPushButton.move(295, 2);

		Simple_QWidget.move(10, 40);
		Slot_QWidget.move(260, 270);
		SlotBack_QLabel.move(260, 270);
		SlotMask_QLabel.move(260, 270);

		Style_QWidget.resize(330, 330);
		QLineBorder_5.resize(328, 1);
		Title_QLabel.resize(328, 29);
		resize(330, 330);
	}
	else
	{
		Space_QWidget.setVisible(true);
		Button_QWidget.setVisible(true);
		Blocks_QWidget.setVisible(true);
		Slots_QWidget.setVisible(true);

		Simple_QPushButton.move(363, 2);
		ATop_QPushButton.move(397, 2);
		Minimize_QPushButton.move(431, 2);
		Close_QPushButton.move(465, 2);

		Simple_QWidget.move(10, 160);
		Slot_QWidget.move(260, 390);
		SlotBack_QLabel.move(260, 390);
		SlotMask_QLabel.move(260, 390);

		Style_QWidget.resize(500, 625);
		QLineBorder_5.resize(498, 1);
		Title_QLabel.resize(498, 29);
		resize(500, 625);
	}
}

void CMainWindow::State_ATop_QPushButton_toggled(const bool checked)
{
	setWindowFlag(Qt::WindowType::WindowStaysOnTopHint, checked);
}