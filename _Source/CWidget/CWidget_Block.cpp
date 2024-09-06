#include "CWidget_Block.h"

#include "../CGeneral/CCore.h"
#include "../CMacro/CSignal.h"

CWidget_Block::CWidget_Block(QWidget *__restrict__ parent) :
	QWidget(parent),

	limit(255),

	Move_QWidget(this),
	Target_QLabel(&Move_QWidget),

	targetBlack(QPixmap(":/Target/Cross-Black.svg").scaled(20, 20, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation)),
	targetWhite(QPixmap(":/Target/Cross-White.svg").scaled(20, 20, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation)),

	valueBeingSet(false)
{
	setAutoFillBackground(true);

	Move_QWidget.setGeometry(-12, -12, 65, 425);
	Target_QLabel.setGeometry(19, 0, 24, 24);
	Target_QLabel.setAlignment(Qt::AlignCenter);
}

void CWidget_Block::SetEnabled(const bool value)
{
	setEnabled(value);

	if (value)
		Target_QLabel.setVisible(true);
	else
	{
		Target_QLabel.setVisible(false);
		SetBrush(QBrush(QColor::fromRgb(0, 0, 0, 187)));
	}
}

void CWidget_Block::SetGradient(const QColor &__restrict__ x, const QColor &__restrict__ y)
{
	if (valueBeingSet)
		return;

	QLinearGradient grad(0.0, 0.0, 0.0, height());

	grad.setColorAt(0.0, x);
	grad.setColorAt(1.0, y);

	SetBrush(QBrush(grad));
}

void CWidget_Block::SetGradient(const QColor &__restrict__ x, const QColor &__restrict__ y, const QColor &__restrict__ z)
{
	if (valueBeingSet)
		return;

	QLinearGradient grad(0.0, 0.0, 0.0, height());

	grad.setColorAt(0.0, x);
	grad.setColorAt(0.5, y);
	grad.setColorAt(1.0, z);

	SetBrush(QBrush(grad));
}

void CWidget_Block::SetGradientHSL(const int y, const int z)
{
	if (valueBeingSet)
		return;

	QLinearGradient grad(0.0, 0.0, 0.0, height());

	grad.setColorAt(0, QColor::fromHsl(359, y, z));
	grad.setColorAt(1.0 / 6.0, QColor::fromHsl(300, y, z));
	grad.setColorAt(2.0 / 6.0, QColor::fromHsl(240, y, z));
	grad.setColorAt(3.0 / 6.0, QColor::fromHsl(180, y, z));
	grad.setColorAt(4.0 / 6.0, QColor::fromHsl(120, y, z));
	grad.setColorAt(5.0 / 6.0, QColor::fromHsl(60, y, z));
	grad.setColorAt(1, QColor::fromHsl(0, y, z));

	SetBrush(QBrush(grad));
}

void CWidget_Block::SetGradientHSV(const int y, const int z)
{
	if (valueBeingSet)
		return;

	QLinearGradient grad(0.0, 0.0, 0.0, height());

	grad.setColorAt(0, QColor::fromHsv(359, y, z));
	grad.setColorAt(1.0 / 6.0, QColor::fromHsv(300, y, z));
	grad.setColorAt(2.0 / 6.0, QColor::fromHsv(240, y, z));
	grad.setColorAt(3.0 / 6.0, QColor::fromHsv(180, y, z));
	grad.setColorAt(4.0 / 6.0, QColor::fromHsv(120, y, z));
	grad.setColorAt(5.0 / 6.0, QColor::fromHsv(60, y, z));
	grad.setColorAt(1, QColor::fromHsv(0, y, z));

	SetBrush(QBrush(grad));
}

void CWidget_Block::SetBrush(const QBrush &__restrict__ brush)
{
	QPalette pal;
	pal.setBrush(QPalette::ColorRole::Window, QBrush(brush));
	setPalette(pal);
}

void CWidget_Block::mousePressEvent(QMouseEvent *__restrict__ event)
{
	mouseMoveEvent(event);
}

void CWidget_Block::mouseMoveEvent(QMouseEvent *__restrict__ event)
{
	Target_QLabel.move(std::clamp(event->pos().x(), 0, 40), Target_QLabel.y());

	const int y = event->pos().y() <= 0 ? limit
				: event->pos().y() >= Move_QWidget.rect().bottom() - Target_QLabel.height() ? 0
				: GetResult(event->pos().y());

	valueBeingSet = true;
	jump MouseMoved(y);
	valueBeingSet = false;
}

void CWidget_Block::wheelEvent(QWheelEvent *__restrict__ event)
{
	if (event->angleDelta().y() > 0)
	{
		if (Target_QLabel.y() > Move_QWidget.rect().top())
		{
			valueBeingSet = true;
			jump MouseMoved(GetResult(Target_QLabel.y()) + 1);
			valueBeingSet = false;
		}
	}
	else if (event->angleDelta().y() < 0)
	{
		if (Target_QLabel.y() < Move_QWidget.rect().bottom() - Target_QLabel.height())
		{
			valueBeingSet = true;
			jump MouseMoved(GetResult(Target_QLabel.y()) - 1);
			valueBeingSet = false;
		}
	}
}

const int CWidget_Block::GetResult(const int coord) const
{
	const int area = Move_QWidget.rect().bottom() - Move_QWidget.rect().top() - Target_QLabel.height();
	return CCore::RoundToInt(static_cast<double>(area - coord) / static_cast<double>(area) * static_cast<double>(limit));
}

void CWidget_Block::SetResult(const int result, const int lumi)
{
	const int area = Move_QWidget.rect().bottom() - Move_QWidget.rect().top() - Target_QLabel.height();
	Target_QLabel.move(Target_QLabel.x(), CCore::RoundToInt(static_cast<double>(area * (limit - result)) / static_cast<double>(limit)));

	Target_QLabel.setPixmap(lumi < 128 ? targetWhite : targetBlack);
}