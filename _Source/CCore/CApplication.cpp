#include "CApplication.hpp"

#include <QtCore/QCoreApplication>

void CApplication::processEvents() noexcept
{
	QCoreApplication::processEvents(QEventLoop::ProcessEventsFlag::ExcludeUserInputEvents | QEventLoop::ProcessEventsFlag::ExcludeSocketNotifiers);
}