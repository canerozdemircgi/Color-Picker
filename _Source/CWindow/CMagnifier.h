#ifndef CMagnifier_H
#define CMagnifier_H

#include "../CMacro/CAccessor.h"

#include <QtGui/QMouseEvent>
#include <QtWidgets/QLabel>

#include <functional>

#include <opencv2/imgproc/imgproc.hpp>

class CMagnifier : public QWidget
{
public:
	explicit CMagnifier(const bool invert,
						const double magRatio,
						const int magResX,
						const int magResY,
						const cv::InterpolationFlags magQuality,
						const std::function<cv::InterpolationFlags()> &__restrict__ MouseRightPressed,
						const std::function<bool()> &__restrict__ MouseMiddlePressed,
						const std::function<void(const QColor &__restrict__, const QString &__restrict__)> &__restrict__ MouseMoved,
						const std::function<void(const double)> &__restrict__ MouseWheeled);

	GetAccessorPrivateStatic(cv::Mat, screen0, Screen0)
	void InitScreen0(const bool invert);
	cv::InterpolationFlags magQuality;

	void MouseMove(const int x, const int y);
	void MouseLeftRelease();

private:
	QLabel picture;
	QPoint lastPos;

	double magRatio;
	const int magResX;
	const int magResY;
	const int magResOffX;
	const int magResOffY;
	int magFacX;
	int magFacY;
	int magFacOffX;
	int magFacOffY;
	bool invert;

	void mousePressEvent(QMouseEvent *__restrict__ event) override;
	void mouseReleaseEvent(QMouseEvent *__restrict__ event) override;
	void mouseMoveEvent(QMouseEvent *__restrict__ event) override;
	void wheelEvent(QWheelEvent *__restrict__ event) override;

	const std::function<cv::InterpolationFlags()> MouseRightPressed;
	const std::function<bool()> MouseMiddlePressed;
	const std::function<void(const QColor &__restrict__, const QString &__restrict__)> MouseMoved;
	const std::function<void(const double)> MouseWheeled;
};

#endif