#ifndef CError_H
#define CError_H

#include "../CDialog/CMessage.h"

#include <QtCore/QCoreApplication>

#ifndef CErrorReturnBool
#define CErrorReturnBool(ok)\
if (!ok)\
	return false;
#endif

#ifndef CErrorMessageReturnVoid
#define CErrorMessageReturnVoid(ok, title, message, parent)\
if (!ok)\
{\
	new CMessage(title, message, parent);\
	return;\
}
#endif

#ifndef CErrorMessageReturnQuit
#define CErrorMessageReturnQuit(ok, title, message, parent)\
if (!ok)\
{\
	new CMessage(title, message, parent);\
	QCoreApplication::quit();\
}
#endif

#endif