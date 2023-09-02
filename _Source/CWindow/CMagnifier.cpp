#include "CMagnifier.h"

#include "../CGeneral/CCore.h"
#include "../CInput/CDoubleSpinBox.h"
#include "../CMacro/CSignal.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include <QWindow>
#include <QApplication>
#include <QDesktopWidget>

cv::Mat CMagnifier::screen0;

void CMagnifier::InitScreen0(const bool invert)
{
	QRect screenGeometry = qApp->primaryScreen()->virtualGeometry();
	QPixmap screenPixmap = qApp->primaryScreen()->grabWindow(QApplication::desktop()->winId(), screenGeometry.x(), screenGeometry.y(), screenGeometry.width(), screenGeometry.height());

	QImage image0 = /*QGuiApplication::primaryScreen()->grabWindow(0)*/screenPixmap.toImage().convertToFormat(QImage::Format::Format_RGB888);
	screen0 = cv::Mat(
		image0.height(),
		image0.width(),
		CV_8UC3,
		image0.bits(),
		image0.bytesPerLine()
	).clone();
	if(invert)
		bitwise_not(screen0, screen0);
}

CMagnifier::CMagnifier(
	const bool invert,
	const double magRatio,
	const int magResX,
	const int magResY,
	const cv::InterpolationFlags magQuality,
	const std::function<cv::InterpolationFlags()> &__restrict__ MouseRightPressed,
	const std::function<bool()> &__restrict__ MouseMiddlePressed,
	const std::function<void(const QColor &__restrict__, const QString &__restrict__)> &__restrict__ MouseMoved,
	const std::function<void(const double)> &__restrict__ MouseWheeled
) :
	QWidget(),

	magQuality(magQuality),

	picture(this),

	lastPos(QCursor::pos()),

	magRatio(magRatio),
	magResX(magResX),
	magResY(magResY),
	magResOffX(magResX / 2),
	magResOffY(magResY / 2),

	magFacX(CCore::RoundToInt(static_cast<double>(magResX) / magRatio)),
	magFacY(CCore::RoundToInt(static_cast<double>(magResY) / magRatio)),
	magFacOffX(magFacX / 2 - magResOffX),
	magFacOffY(magFacY / 2 - magResOffY),

	invert(invert),

	MouseRightPressed(MouseRightPressed),
	MouseMiddlePressed(MouseMiddlePressed),
	MouseMoved(MouseMoved),
	MouseWheeled(MouseWheeled)
{
	setWindowFlag(Qt::WindowType::WindowStaysOnTopHint);
	setWindowFlag(Qt::WindowType::FramelessWindowHint, true);
	setCursor(Qt::CursorShape::CrossCursor);

	setMinimumSize(magResX, magResY);
	setMaximumSize(magResX, magResY);
	picture.resize(magResX, magResY);

	InitScreen0(invert);
	copyMakeBorder(
		screen0, screen0,
		magResOffY, magResOffY,
		magResOffX, magResOffX,
		cv::BorderTypes::BORDER_CONSTANT
	);

	setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
	show();
	MouseMove(lastPos.x(), lastPos.y());
}

void CMagnifier::mousePressEvent(QMouseEvent *__restrict__ event)
{
	if(event->button() == Qt::MouseButton::LeftButton)
	{
		setWindowOpacity(0.0);
		InitScreen0(invert);
		copyMakeBorder(
			screen0, screen0,
			magResOffY, magResOffY,
			magResOffX, magResOffX,
			cv::BorderTypes::BORDER_CONSTANT
		);
		setWindowOpacity(1.0);

		QPoint posOld = geometry().center();
		setWindowFlag(Qt::WindowType::FramelessWindowHint, true);
		show();
		QPoint posNew = geometry().center();
		move(pos() - (posNew - posOld));
	}
	else if(event->button() == Qt::MouseButton::RightButton)
	{
		magQuality = jump MouseRightPressed();
		MouseMove(lastPos.x(), lastPos.y());
	}
	else if(event->button() == Qt::MouseButton::MiddleButton)
	{
		invert = jump MouseMiddlePressed();
		bitwise_not(screen0, screen0);
		MouseMove(lastPos.x(), lastPos.y());
	}
}

void CMagnifier::mouseReleaseEvent(QMouseEvent *__restrict__ event)
{
	if(event->button() == Qt::MouseButton::LeftButton)
	{
		lastPos = event->globalPos();
		MouseMove(lastPos.x(), lastPos.y());
		MouseLeftRelease();
	}
}

void CMagnifier::MouseLeftRelease()
{
	QPoint posOld = geometry().center();
	setWindowFlag(Qt::WindowType::FramelessWindowHint, false);
	show();
	QPoint posNew = geometry().center();
	move(pos() - (posNew - posOld));
}

void CMagnifier::mouseMoveEvent(QMouseEvent *__restrict__ event)
{
	lastPos = event->globalPos();
	MouseMove(lastPos.x(), lastPos.y());
}

void CMagnifier::MouseMove(const int x, const int y)
{
	move(pos() + (QPoint(x, y) - geometry().center()));

	const cv::Rect cropped(x - magFacOffX, y - magFacOffY, magFacX, magFacY);
	cv::Mat screen0Cropped(screen0(cropped));
	cv::resize(screen0Cropped, screen0Cropped, cv::Size(magResX, magResY), 0, 0, magQuality);
	picture.setPixmap(QPixmap::fromImage(QImage(screen0Cropped.data,
												screen0Cropped.cols,
												screen0Cropped.rows,
												screen0Cropped.step,
												QImage::Format::Format_RGB888)));

	const QPoint coord(picture.mapFromGlobal(QPoint(x, y)));
	int id = screen0Cropped.channels() * (screen0Cropped.cols * coord.y() + coord.x()) - 1;
	const int r = static_cast<int>(screen0Cropped.data[++id]);
	const int g = static_cast<int>(screen0Cropped.data[++id]);
	const int b = static_cast<int>(screen0Cropped.data[++id]);
	jump MouseMoved(QColor::fromRgb(r, g, b), QString::number(x) + "\n" + QString::number(y));
}

void CMagnifier::wheelEvent(QWheelEvent *__restrict__ event)
{
	const double val = event->angleDelta().y() > 0 ? 0.1 : -0.1;
	if(magRatio + val >= 1.0 - 1.0 / pow(10.0, CDoubleSpinBox::precision))
	{
		magRatio += val;

		magFacX = CCore::RoundToInt(static_cast<double>(magResX) / magRatio);
		magFacY = CCore::RoundToInt(static_cast<double>(magResY) / magRatio);
		magFacOffX = magFacX / 2 - magResOffX;
		magFacOffY = magFacY / 2 - magResOffY;

		jump MouseWheeled(magRatio);
		MouseMove(lastPos.x(), lastPos.y());
	}
}