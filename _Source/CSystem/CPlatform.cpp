#include "CPlatform.hpp"

#ifdef _WIN32
#include <windef.h>
#include <winbase.h>
#include <winuser.h>
#endif

#include <QtCore/QAbstractNativeEventFilter>
#include <QtCore/QCoreApplication>
#include <QtWidgets/QWidget>

// TODO: implement linux counterpart
void CPlatform::setProcessPriority(CPlatform::Priority priority)
{
	#ifdef _WIN32
	const DWORD dword = [](CPlatform::Priority priority)
	{
		switch (priority)
		{
			case CPlatform::Priority::LOW:
				return IDLE_PRIORITY_CLASS;
			case CPlatform::Priority::HIGH:
				return HIGH_PRIORITY_CLASS;
			default:
				return NORMAL_PRIORITY_CLASS;
		}
	}(priority);
	SetPriorityClass(GetCurrentProcess(), dword);
	#endif
}

#ifdef _WIN32
void CPlatform::fixResize()
{
	static class CNativeEventFilter final : public QAbstractNativeEventFilter
	{
	private:
		bool nativeEventFilter(const QByteArray& /*eventType*/, void* const message, qintptr* const /*result*/) override
		{
			if (const MSG* const msg = static_cast<const MSG*>(message); msg->message == WM_NCCALCSIZE && msg->wParam == TRUE)
			{
				if (const QWidget* const widget = QWidget::find(reinterpret_cast<WId>(msg->hwnd)))
				{
					if (const QVariant c = widget->property("C"); c.isValid() && c.value<bool>())
					{
						NCCALCSIZE_PARAMS* const params = reinterpret_cast<NCCALCSIZE_PARAMS*>(msg->lParam);
						++params->rgrc[0].right;
						return true;
					}
				}
			}
			return false;
		}
	} filter;

	struct InstallFilter
	{
		InstallFilter()
		{
			QCoreApplication::instance()->installNativeEventFilter(&filter);
		}
	};
	static const InstallFilter _;
}
#endif