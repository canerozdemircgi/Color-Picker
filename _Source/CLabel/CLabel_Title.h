#ifndef CLabel_Title_H
#define CLabel_Title_H

#include <QtGui/QMouseEvent>
#include <QtWidgets/QLabel>

class CLabel_Title : public QLabel
{
public:
	explicit CLabel_Title(QWidget *__restrict__ parent);

private:
	QWidget *__restrict__ window;
	QPoint posOld;

	void mousePressEvent(QMouseEvent *__restrict__ event) override;
	void mouseMoveEvent(QMouseEvent *__restrict__ event) override;
	void mouseReleaseEvent(QMouseEvent *__restrict__ event) override;
};

#endif