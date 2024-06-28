#include "CConfig.h"

#include "../CDialog/CMessage.h"
#include "../CGeneral/CCore.h"
#include "../CGeneral/CStyle.h"
#include "../CInput/CDoubleSpinBox.h"
#include "../CMacro/CSignal.h"

#include <QtWidgets/QFileDialog>

int CConfig::startSlots;
QString CConfig::colorEmpty;
QString CConfig::colorCustom;

CConfig::CConfig(const std::function<void(const int)> &__restrict__ state_FloatPrec_QSpinBox_valueChanged, const QWidget *__restrict__ parent) :
        QDialog(),

        Title_QLabel(this),

        Icon_QLabel(this),
        Close_QPushButton(this),

        StartSlots_QLabel(this),
        StartSlots_QComboBox(this),
        CustomSlot_QLineEdit(this),
        CustomSlot_QPushButton(this),

        EmptyColor_QLabel(this),
        EmptyColor_QLineEdit(this),
        FloatPrec_QLabel(this),
        FloatPrec_QSpinBox(this),

        QLineBorder_5(this),

        state_FloatPrec_QSpinBox_valueChanged(state_FloatPrec_QSpinBox_valueChanged)
{
	setGeometry(parent->geometry().center().x() - 370 / 2, parent->geometry().center().y() - 100 / 2, 370, 100);

	setAccessibleName("QMain");
	setWindowFlags(Qt::WindowType::FramelessWindowHint | Qt::WindowType::WindowStaysOnTopHint);

	Title_QLabel.setGeometry(1, 1, 348, 29);
	Title_QLabel.setIndent(38);
	Title_QLabel.setFont(CStyle::fontTitle);
	Title_QLabel.setText("Color-Picker Configuration");

	Icon_QLabel.setGeometry(2, 2, 28, 27);
	Icon_QLabel.setPixmap(QPixmap(":/Logo/Color Picker.svg"));
	Icon_QLabel.setAccessibleName("QLabelImage");
	Close_QPushButton.setGeometry(335, 2, 33, 27);
	Close_QPushButton.setIcon(QPixmap(":/Button/Radio.svg"));
	Close_QPushButton.setToolTip("Close");
	Close_QPushButton.setToolTipDuration(60000);

	StartSlots_QLabel.setGeometry(10, 40, 90, 20);
	StartSlots_QLabel.setText("Start Slots As");
	StartSlots_QComboBox.setGeometry(110, 40, 70, 20);
	StartSlots_QComboBox.insertItems(0, QList<QString>()
		<< "Random"
		<< "Empty"
		<< "Custom"
	);
	StartSlots_QComboBox.setCurrentIndex(startSlots);
	if (startSlots != 2)
	{
		CustomSlot_QLineEdit.setEnabled(false);
		CustomSlot_QPushButton.setEnabled(false);
	}
	CustomSlot_QLineEdit.setGeometry(190, 40, 170, 20);
	CustomSlot_QLineEdit.setTextMargins(0, 0, 19, 0);
	CustomSlot_QLineEdit.setText(colorCustom);
	CustomSlot_QPushButton.setGeometry(341, 41, 18, 18);
	CustomSlot_QPushButton.setIcon(QPixmap(":/Direction/Right.svg").scaled(6, 6, Qt::AspectRatioMode::IgnoreAspectRatio, Qt::TransformationMode::SmoothTransformation));

	EmptyColor_QLabel.setGeometry(10, 70, 90, 20);
	EmptyColor_QLabel.setText("Empty Color Hex");
	EmptyColor_QLineEdit.setGeometry(110, 70, 70, 20);
	EmptyColor_QLineEdit.setText(colorEmpty);
	FloatPrec_QLabel.setGeometry(190, 70, 120, 20);
	FloatPrec_QLabel.setText("Float Display Precision");
	FloatPrec_QSpinBox.setGeometry(320, 70, 40, 20);
	FloatPrec_QSpinBox.setAlignment(Qt::AlignmentFlag::AlignCenter);
	FloatPrec_QSpinBox.setMaximum(9);
	FloatPrec_QSpinBox.setValue(CDoubleSpinBox::precision);

	QLineBorder_5.setGeometry(1, 30, 368, 1);
	QLineBorder_5.setFrameShadow(QFrame::Shadow::Plain);
	QLineBorder_5.setFrameShape(QFrame::Shape::HLine);

	connect(&StartSlots_QComboBox, static_cast<void(QComboBox::*)(const int)>(&QComboBox::currentIndexChanged), this, &CConfig::State_StartSlots_QComboBox_currentIndexChanged, CCore::connection);
	connect(&CustomSlot_QLineEdit, &QLineEdit::textEdited, this, &CConfig::State_CustomSlot_QLineEdit_textEdited, CCore::connection);
	connect(&EmptyColor_QLineEdit, &QLineEdit::returnPressed, this, &CConfig::State_EmptyColor_QLineEdit_returnPressed, CCore::connection);
	connect(&FloatPrec_QSpinBox, static_cast<void(QSpinBox::*)(const int)>(&QSpinBox::valueChanged), this, &CConfig::State_FloatPrec_QSpinBox_valueChanged, CCore::connection);

	CustomSlot_QPushButton.MouseLeftReleased = std::bind(&CConfig::State_CustomSlot_QPushButton_MouseLeftReleased, this);
	Close_QPushButton.MouseLeftReleased = std::bind(reinterpret_cast<bool(CConfig::*)()>(&CConfig::close), this);

	setStyleSheet(CStyle::styleSheet);
	setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
	exec();
}

void CConfig::State_StartSlots_QComboBox_currentIndexChanged(const int index)
{
	startSlots = index;

	const bool value = index == 2;
	CustomSlot_QLineEdit.setEnabled(value);
	CustomSlot_QPushButton.setEnabled(value);
}

void CConfig::State_CustomSlot_QLineEdit_textEdited(const QString &__restrict__ arg)
{
	colorCustom = arg;
}

void CConfig::State_CustomSlot_QPushButton_MouseLeftReleased()
{
	const QString fileName(QFileDialog::getOpenFileName(this, "Color File Load", nullptr, "Color Files (*.clr)"));
	if (fileName != nullptr)
	{
		colorCustom = fileName;
		CustomSlot_QLineEdit.setText(fileName);
	}
}

void CConfig::State_EmptyColor_QLineEdit_returnPressed() const
{
	QString hexadecimal(EmptyColor_QLineEdit.text());
	if (hexadecimal[0] != '#')
		hexadecimal = '#' + hexadecimal;

	if (hexadecimal.size() == 9)
	{
		new CMessage
        (
			"Warning",
			"Alpha Is Not Allowed, Try Again",
            this
		);
		return;
	}

	if (QColor(hexadecimal).isValid())
		colorEmpty = hexadecimal;
	else
		new CMessage
        (
			"Warning",
			"Wrong Hexadecimal Value, Try Again",
            this
		);
}

void CConfig::State_FloatPrec_QSpinBox_valueChanged(const int arg) const
{
    state_FloatPrec_QSpinBox_valueChanged(arg);
}