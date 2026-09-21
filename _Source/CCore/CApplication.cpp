#include "CApplication.hpp"

#include <QtCore/QCoreApplication>

void CApplication::processEvents()
{
	QCoreApplication::processEvents(QEventLoop::ProcessEventsFlag::ExcludeUserInputEvents | QEventLoop::ProcessEventsFlag::ExcludeSocketNotifiers);
}