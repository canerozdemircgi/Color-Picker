#include "CWidget_Slot.h"

#include "../CGeneral/CCore.h"
#include "../CMacro/CSignal.h"

CWidget_Slot *__restrict__ CWidget_Slot::selected;

std::function<void()> CWidget_Slot::MouseLeftPressed;
std::function<void(const int)> CWidget_Slot::MouseWheeled;

CWidget_Slot::CWidget_Slot(const int index, QWidget *__restrict__ parent) :
	QWidget(parent),

	index(index),

	rgb1(0), rgb2(0), rgb3(0),
	hsl1(0), hsl2(0), hsl3(0),
	hsv1(0), hsv2(0), hsv3(0),
	lumi(0), intp(0), alph(0),

	Mask_QLabel(this),
	Target_QLabel(this),

	targetBlack(QPixmap(":/Target/1 Black.svg")),
	targetWhite(QPixmap(":/Target/1 White.svg"))
{
	setAutoFillBackground(true);

	Mask_QLabel.setGeometry(0, 0, 30, 30);
	Target_QLabel.setVisible(false);
	Target_QLabel.setGeometry(3, 3, 24, 24);
}

void CWidget_Slot::SetSelectedInit()
{
	selected = this;
	Mask_QLabel.setVisible(false);
	Target_QLabel.setVisible(true);
}

void CWidget_Slot::SetSelected()
{
	selected->Mask_QLabel.setVisible(true);
	selected->Target_QLabel.setVisible(false);
	selected = this;
	Mask_QLabel.setVisible(false);
	Target_QLabel.setVisible(true);
}

void CWidget_Slot::SetColor(const QColor &__restrict__ color)
{
	this->color = color;

	color.getRgb(&rgb1, &rgb2, &rgb3, &alph);
	color.getHsl(&hsl1, &hsl2, &hsl3);
	color.getHsv(&hsv1, &hsv2, &hsv3);

	lumi = CCore::Lumina(rgb1, rgb2, rgb3);
	intp = CCore::Interp(rgb1, rgb2, rgb3);

	QPalette pal;
	pal.setColor(QPalette::ColorRole::Window, color.rgb());
	setPalette(pal);

	if (lumi < 128)
		Target_QLabel.setPixmap(targetWhite);
	else
		Target_QLabel.setPixmap(targetBlack);
}

void CWidget_Slot::mousePressEvent(QMouseEvent *__restrict__ event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
	{
		SetSelected();
		jump MouseLeftPressed();
	}
}

void CWidget_Slot::wheelEvent(QWheelEvent *__restrict__ event)
{
	jump MouseWheeled(event->angleDelta().y() > 0 ? -1 : 1);
}