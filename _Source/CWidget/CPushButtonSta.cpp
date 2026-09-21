#include "CPushButtonSta.hpp"

#include <QtGui/QMouseEvent>

CPushButtonSta::CPushButtonSta(QWidget* const parent) :
	QPushButton(parent)
{
}

QMouseEvent CPushButtonSta::redirectMouseEvent(const QMouseEvent& event)
{
	return CPushButtonSta::redirectMouseEvent(event, event.type());
}

QMouseEvent CPushButtonSta::redirectMouseEvent(const QMouseEvent& event, QEvent::Type type)
{
	return
	{
		type,
		event.position(),
		event.scenePosition(),
		event.globalPosition(),
		Qt::MouseButton::LeftButton,
		Qt::MouseButton::LeftButton,
		event.modifiers(),
		event.source(),
		event.pointingDevice()
	};
}

void CPushButtonSta::mousePressAndRelease()
{
	const QMouseEvent event
	{
		QEvent::Type::None,
		QPointF(),
		QPointF(),
		QPointF(),
		Qt::MouseButton::NoButton,
		Qt::MouseButton::NoButton,
		Qt::KeyboardModifier::NoModifier
	};

	QMouseEvent eventR1 = CPushButtonSta::redirectMouseEvent(event, QEvent::Type::MouseButtonPress);
	QCoreApplication::sendEvent(this, &eventR1);
	QMouseEvent eventR2 = CPushButtonSta::redirectMouseEvent(event, QEvent::Type::MouseButtonRelease);
	QCoreApplication::sendEvent(this, &eventR2);
}

void CPushButtonSta::setChecked(bool checked)
{
	if (this->isChecked() != checked)
		this->mousePressAndRelease();
}

void CPushButtonSta::mousePressEvent(QMouseEvent* const event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
		QPushButton::mousePressEvent(event);
	else
	{
		QMouseEvent eventR = CPushButtonSta::redirectMouseEvent(*event);
		QPushButton::mousePressEvent(&eventR);
	}
}

void CPushButtonSta::mouseReleaseEvent(QMouseEvent* const event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
		QPushButton::mouseReleaseEvent(event);
	else
	{
		QMouseEvent eventR = CPushButtonSta::redirectMouseEvent(*event);
		QPushButton::mouseReleaseEvent(&eventR);
	}

	if (this->rect().contains(event->pos()))
	{
		if (this->mouseReleased)
			this->mouseReleased();
		else
		{
			if (this->mouseLeftReleased && event->button() == Qt::MouseButton::LeftButton)
				this->mouseLeftReleased();
			else if (this->mouseRightReleased && event->button() == Qt::MouseButton::RightButton)
				this->mouseRightReleased();
			else if (this->mouseMiddleReleased && event->button() == Qt::MouseButton::MiddleButton)
				this->mouseMiddleReleased();
		}
	}
}

void CPushButtonSta::keyPressEvent(QKeyEvent* const event)
{
	QPushButton::keyPressEvent(event);

	if (this->hasFocus() && (event->key() == Qt::Key::Key_Space || event->key() == Qt::Key::Key_Return || event->key() == Qt::Key::Key_Enter))
	{
		if (this->mouseReleased)
			this->mouseReleased();
		else if (this->mouseLeftReleased)
			this->mouseLeftReleased();
	}
}