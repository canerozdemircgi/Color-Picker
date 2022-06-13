#ifndef CWidget_Block_H
#define CWidget_Block_H

#include <QtGui/QMouseEvent>
#include <QtWidgets/QLabel>

#include <functional>

class CWidget_Block : public QWidget
{
public:
	explicit CWidget_Block(QWidget *__restrict__ parent);

	void SetEnabled(const bool value);

	int limit;

	void SetGradient(const QColor &__restrict__ x, const QColor &__restrict__ y);
	void SetGradient(const QColor &__restrict__ x, const QColor &__restrict__ y, const QColor &__restrict__ z);
	void SetGradientHSL(const int y, const int z);
	void SetGradientHSV(const int y, const int z);

	void SetResult(const int result, const int lumi);

	std::function<void(const int)> MouseMoved;

private:
	QWidget Move_QWidget;
	QLabel Target_QLabel;

	const QPixmap targetBlack;
	const QPixmap targetWhite;

	bool valueBeingSet;

	void SetBrush(const QBrush &__restrict__ brush);

	int GetResult(const int coord) const;

	void mousePressEvent(QMouseEvent *__restrict__ event) override;
	void mouseMoveEvent(QMouseEvent *__restrict__ event) override;
	void wheelEvent(QWheelEvent *__restrict__ event) override;
};

#endif