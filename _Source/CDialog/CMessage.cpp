#include "CMessage.h"

#include "../CGeneral/CStyle.h"

CMessage::CMessage(const QString &__restrict__ title, const QString &__restrict__ message, const QWidget *__restrict__ parent) :
	QDialog(),

	Title_QLabel(this),

	Icon_QLabel(this),
	Close_QPushButton(this),

	Message_QLabel(this),

	QLineBorder_5(this)
{
	setAccessibleName("QMain");
	setWindowFlags(Qt::WindowType::FramelessWindowHint | Qt::WindowType::WindowStaysOnTopHint);

	Title_QLabel.setIndent(38);
	Title_QLabel.setFont(CStyle::fontTitle);
	Title_QLabel.setText(title);

	Icon_QLabel.setPixmap(QPixmap(":/Logo/Color Picker.svg"));
	Icon_QLabel.setAccessibleName("QLabelImage");
	Close_QPushButton.setText("OK");
	Close_QPushButton.setDefault(true);

	Message_QLabel.setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByMouse);
	Message_QLabel.setText(message);

	QLineBorder_5.setFrameShadow(QFrame::Shadow::Plain);
	QLineBorder_5.setFrameShape(QFrame::Shape::HLine);

	const int sizeXMessage = (Message_QLabel.sizeHint().width() + 10) / 10 * 10;
	const int sizeYMessage = (Message_QLabel.sizeHint().height() + 10) / 10 * 10;
	const int sizeX = sizeXMessage + 40;
	const int sizeY = sizeYMessage + 105;
	const int sizeX0 = sizeX - 2;

	setGeometry(parent->geometry().center().x() - sizeX / 2, parent->geometry().center().y() - sizeY / 2, sizeX, sizeY);

	Title_QLabel.setGeometry(1, 1, sizeX0, 29);

	Icon_QLabel.setGeometry(2, 2, 28, 27);
	Close_QPushButton.setGeometry(sizeX - 90, sizeY - 35, 80, 25);

	Message_QLabel.setGeometry(20, 50, sizeXMessage, sizeYMessage);

	QLineBorder_5.setGeometry(1, 30, sizeX0, 1);

	Close_QPushButton.MouseLeftReleased = std::bind(reinterpret_cast<bool(CMessage::*)()>(&CMessage::close), this);

	setStyleSheet(CStyle::styleSheet);
	setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
	exec();
}