#ifndef CPushButton_Sta_H
#define CPushButton_Sta_H

#include <QtGui/QMouseEvent>
#include <QtWidgets/QPushButton>

#include <functional>

class CPushButton_Sta : public QPushButton
{
public:
	explicit CPushButton_Sta(QWidget *__restrict__ parent);

	std::function<void()> MouseLeftReleased;
	std::function<void()> MouseRightReleased;
	std::function<void()> MouseMiddleReleased;

private:
	void mouseReleaseEvent(QMouseEvent *__restrict__ event) override;
};

#endif