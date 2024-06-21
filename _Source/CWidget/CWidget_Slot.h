#ifndef CWidget_Slot_H
#define CWidget_Slot_H

#include "../CLabel/CLabel_Mask.h"
#include "../CMacro/CAccessor.h"

#include <functional>

class CWidget_Slot : public QWidget
{
public:
	explicit CWidget_Slot(const int index, QWidget *__restrict__ parent);

	GetAccessorPrivateStaticPointer(CWidget_Slot, selected, Selected)
	void SetSelectedInit();
	void SetSelected();

	const int index;
	QString name;
	QString tag;

	GetAccessorPrivate(QColor, color, Color)
	void SetColor(const QColor &__restrict__ color);

	GetAccessorPrivate(int, rgb1, Rgb1)
	GetAccessorPrivate(int, rgb2, Rgb2)
	GetAccessorPrivate(int, rgb3, Rgb3)

	GetAccessorPrivate(int, hsl1, Hsl1)
	GetAccessorPrivate(int, hsl2, Hsl2)
	GetAccessorPrivate(int, hsl3, Hsl3)

	GetAccessorPrivate(int, hsv1, Hsv1)
	GetAccessorPrivate(int, hsv2, Hsv2)
	GetAccessorPrivate(int, hsv3, Hsv3)

	GetAccessorPrivate(int, lumi, Lumi)
	GetAccessorPrivate(int, intp, Intp)
	GetAccessorPrivate(int, alph, Alph)

	static std::function<void()> MouseLeftPressed;
	static std::function<void(const int)> MouseWheeled;

private:
	CLabel_Mask Mask_QLabel;
	QLabel Target_QLabel;

	const QPixmap targetBlack;
	const QPixmap targetWhite;

	void mousePressEvent(QMouseEvent *__restrict__ event) override;
	void wheelEvent(QWheelEvent *__restrict__ event) override;
};

#endif