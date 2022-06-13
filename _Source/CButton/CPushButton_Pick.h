#ifndef CPushButton_Pick_H
#define CPushButton_Pick_H

#include <QtGui/QMouseEvent>
#include <QtWidgets/QPushButton>

#include <functional>

class CPushButton_Pick : public QPushButton
{
public:
	explicit CPushButton_Pick(QWidget *__restrict__ parent);

	std::function<void()> MouseLeftPressed;
	std::function<void()> MouseRightPressed;
	std::function<void()> MouseMiddlePressed;
	std::function<void()> MouseMoved;
	std::function<void()> MouseReleased;

private:
	void mousePressEvent(QMouseEvent *__restrict__ event) override;
	void mouseReleaseEvent(QMouseEvent *__restrict__ event) override;
	void mouseMoveEvent(QMouseEvent *__restrict__ event) override;
};

#endif