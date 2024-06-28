#include "../CMainWindow.h"

#include "CDialog/CConfig.h"
#include "CDialog/CMessage.h"
#include "CGeneral/CCore.h"
#include "CMacro/CError.h"

#include <QtCore/QTextStream>
#include <QtCore/QFile>

void CMainWindow::ConfigReset() const
{
	QFile config(CCore::fileConfig);
	if (config.open(QIODevice::OpenModeFlag::WriteOnly))
	{
		QTextStream stream(&config);

		stream
			<< "0 0" << Qt::endl
			<< "0 #808080 " << Qt::endl
			<< "0 1" << Qt::endl

			<< "0 0" << Qt::endl
			<< "0 3 0 2.2" << Qt::endl
			<< "4.0 256 256 0 0" << Qt::endl

			<< "-255 255" << Qt::endl
			<< "-255 255" << Qt::endl
			<< "-255 255" << Qt::endl
			<< "0 255" << Qt::endl

			<< x() << ' ' << y();

		config.close();
		new CMessage
        (
			"Success",
			"Configurations Have Been Resetted\n" + CCore::fileConfig,
            this
		);
	}
	else
		new CMessage
        (
			"Error",
			"Please Check File Permissions\n" + CCore::fileConfig,
            this
		);
}

bool CMainWindow::ConfigLoad()
{
	QFile config(CCore::fileConfig);
	if (config.open(QIODevice::OpenModeFlag::ReadOnly))
	{
		bool ok;

		QTextStream stream(&config);
		const QList<QString> lines(CCore::SeparateQString(stream.readAll(), '\n', 11, &ok));
		config.close();
		CErrorReturnBool(ok);

		int i = -1;

		QList<QString> line(CCore::SeparateQString(lines[++i], ' ', 2, &ok));
		CErrorReturnBool(ok);
		const int slotIndex = line[0].toInt(&ok);
		CErrorReturnBool(ok);
		CErrorReturnBool((slotIndex >= 0 && slotIndex < slotSize));
		const int modeIndex = line[1].toInt(&ok);
		CErrorReturnBool(ok);
		CErrorReturnBool((modeIndex >= 0 && modeIndex < modeSize));
		slot[slotIndex]->SetSelectedInit();
		mode[modeIndex]->setChecked(true);

		line = CCore::SeparateQString(lines[++i], ' ', 3, &ok);
		CErrorReturnBool(ok);
		CConfig::startSlots = line[0].toInt(&ok);
		CErrorReturnBool(ok);
		CConfig::colorEmpty = line[1];
		CConfig::colorCustom = line[2];

		line = CCore::SeparateQString(lines[++i], ' ', 2, &ok);
		CErrorReturnBool(ok);
		Simple_QPushButton.setChecked(line[0].toInt(&ok));
		CErrorReturnBool(ok);
		ATop_QPushButton.setChecked(line[1].toInt(&ok));
		CErrorReturnBool(ok);

		line = CCore::SeparateQString(lines[++i], ' ', 2, &ok);
		CErrorReturnBool(ok);
		Alpha_QCheckBox.setChecked(line[0].toInt(&ok));
		CErrorReturnBool(ok);
		Alpha_QComboBox.setCurrentIndex(line[1].toInt(&ok));
		CErrorReturnBool(ok);

		line = CCore::SeparateQString(lines[++i], ' ', 4, &ok);
		CErrorReturnBool(ok);
		Float_QCheckBox.setChecked(line[0].toInt(&ok));
		CErrorReturnBool(ok);
		State_FloatPrec_QSpinBox_valueChanged(line[1].toInt(&ok));
		CErrorReturnBool(ok);
		Gamma_QCheckBox.setChecked(line[2].toInt(&ok));
		CErrorReturnBool(ok);
		Gamma_QDSpinBox.setValue(line[3].toDouble(&ok));
		CErrorReturnBool(ok);

		line = CCore::SeparateQString(lines[++i], ' ', 5, &ok);
		CErrorReturnBool(ok);
		MagnifyRat_QDSpinBox.setValue(line[0].toDouble(&ok));
		CErrorReturnBool(ok);
		MagnifyResX_QSpinBox.setValue(line[1].toInt(&ok));
		CErrorReturnBool(ok);
		MagnifyResY_QSpinBox.setValue(line[2].toInt(&ok));
		CErrorReturnBool(ok);
		MagnifyQuality_QComboBox.setCurrentIndex(line[3].toInt(&ok));
		CErrorReturnBool(ok);
		MagnifyInvert_QCheckBox.setChecked(line[4].toInt(&ok));
		CErrorReturnBool(ok);

		line = CCore::SeparateQString(lines[++i], ' ', 2, &ok);
		CErrorReturnBool(ok);
		XMin_QDSpinBox.SetResult(line[0].toInt(&ok));
		CErrorReturnBool(ok);
		XMax_QDSpinBox.SetResult(line[1].toInt(&ok));
		CErrorReturnBool(ok);

		line = CCore::SeparateQString(lines[++i], ' ', 2, &ok);
		CErrorReturnBool(ok);
		YMin_QDSpinBox.SetResult(line[0].toInt(&ok));
		CErrorReturnBool(ok);
		YMax_QDSpinBox.SetResult(line[1].toInt(&ok));
		CErrorReturnBool(ok);

		line = CCore::SeparateQString(lines[++i], ' ', 2, &ok);
		CErrorReturnBool(ok);
		ZMin_QDSpinBox.SetResult(line[0].toInt(&ok));
		CErrorReturnBool(ok);
		ZMax_QDSpinBox.SetResult(line[1].toInt(&ok));
		CErrorReturnBool(ok);

		line = CCore::SeparateQString(lines[++i], ' ', 2, &ok);
		CErrorReturnBool(ok);
		WMin_QDSpinBox.SetResult(line[0].toInt(&ok));
		CErrorReturnBool(ok);
		WMax_QDSpinBox.SetResult(line[1].toInt(&ok));
		CErrorReturnBool(ok);

		line = CCore::SeparateQString(lines[++i], ' ', 2, &ok);
		CErrorReturnBool(ok);
		const int x = line[0].toInt(&ok);
		CErrorReturnBool(ok);
		const int y = line[1].toInt(&ok);
		CErrorReturnBool(ok);
		move(x, y);

		return true;
	}

	return false;
}

void CMainWindow::ConfigSave() const
{
	QFile config(CCore::fileConfig);
	if (config.open(QIODevice::OpenModeFlag::WriteOnly))
	{
		QTextStream stream(&config);

		stream
			<< CWidget_Slot::Selected()->index << ' '
			<< CRadioButton_Mode::indexSelected << Qt::endl

			<< CConfig::startSlots << ' '
			<< CConfig::colorEmpty << ' '
			<< CConfig::colorCustom << Qt::endl

			<< Simple_QPushButton.isChecked() << ' '
			<< ATop_QPushButton.isChecked() << Qt::endl

			<< Alpha_QCheckBox.isChecked() << ' '
			<< Alpha_QComboBox.currentIndex() << Qt::endl

			<< Float_QCheckBox.isChecked() << ' '
			<< CDoubleSpinBox::precision << ' '
			<< Gamma_QCheckBox.isChecked() << ' '
			<< Gamma_QDSpinBox.value() << Qt::endl

			<< MagnifyRat_QDSpinBox.value() << ' '
			<< MagnifyResX_QSpinBox.value() << ' '
			<< MagnifyResY_QSpinBox.value() << ' '
			<< MagnifyQuality_QComboBox.currentIndex() << ' '
			<< MagnifyInvert_QCheckBox.isChecked() << Qt::endl

			<< XMin_QDSpinBox.Result() << ' '
			<< XMax_QDSpinBox.Result() << Qt::endl
			<< YMin_QDSpinBox.Result() << ' '
			<< YMax_QDSpinBox.Result() << Qt::endl
			<< ZMin_QDSpinBox.Result() << ' '
			<< ZMax_QDSpinBox.Result() << Qt::endl
			<< WMin_QDSpinBox.Result() << ' '
			<< WMax_QDSpinBox.Result() << Qt::endl

			<< x() << ' ' << y();

		config.close();
	}
	else
		new CMessage
        (
			"Error",
			"Please Check File Permissions\n" + CCore::fileConfig,
            this
		);
}