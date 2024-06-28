#ifndef CLabel_Mask_H
#define CLabel_Mask_H

#include <QtGui/QMouseEvent>
#include <QtWidgets/QLabel>

class CLabel_Mask : public QLabel
{
public:
	explicit CLabel_Mask(QWidget *__restrict__ parent);

private:
	const QPixmap pixmap;

	void enterEvent(QEnterEvent *__restrict__ event) override;
	void leaveEvent(QEvent *__restrict__ event) override;
};

#endif