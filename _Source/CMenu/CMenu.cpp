#include "CMenu.hpp"

#include "CGui/CGui.hpp"

#include <QtGui/QMouseEvent>
#include <QtGui/QWindow>

using namespace Qt::Literals::StringLiterals;

CMenu::CMenu(QWidget* const parent, const CMenu::Parameters& parameters) :
	QMenu(parent),

	offset(parameters.offsetX, parameters.offsetY)
{
	CGui::makeFrameless(this, Qt::WindowType::ToolTip);
	this->setAccessibleName(u"CMenu"_s);
}

void CMenu::toggle()
{
	if (this->isVisible())
	{
		this->close();
		this->parentWidget()->window()->windowHandle()->removeEventFilter(this);
	}
	else
	{
		this->move();
		this->show();
		this->parentWidget()->window()->windowHandle()->installEventFilter(this);
	}
}

void CMenu::move()
{
	QMenu::move(this->parentWidget()->mapToGlobal(this->parentWidget()->rect().bottomLeft() + offset));
}

void CMenu::mouseReleaseEvent(QMouseEvent* const event)
{
	QMenu::mouseReleaseEvent(event);

	if (QAction* const action = this->activeAction())
	{
		if (event->button() == Qt::MouseButton::RightButton || event->button() == Qt::MouseButton::MiddleButton)
			action->trigger();
	}
}

bool CMenu::eventFilter(QObject* const object, QEvent* const event)
{
	const bool eventFilter = QMenu::eventFilter(object, event);

	if (event->type() == QEvent::Type::Move || event->type() == QEvent::Type::Resize)
		this->move();

	return eventFilter;
}