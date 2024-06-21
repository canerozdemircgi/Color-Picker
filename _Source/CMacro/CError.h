#ifndef CError_H
#define CError_H

#include "../CDialog/CMessage.h"

#include <QtCore/QCoreApplication>

#ifndef CErrorReturnBool
#define CErrorReturnBool(ok)\
if(!ok)\
	return false;
#endif

#ifndef CErrorMessageReturnVoid
#define CErrorMessageReturnVoid(ok, parent, title, message)\
if(!ok)\
{\
	new CMessage(parent, title, message);\
	return;\
}
#endif

#ifndef CErrorMessageReturnQuit
#define CErrorMessageReturnQuit(ok, parent, title, message)\
if(!ok)\
{\
	new CMessage(parent, title, message);\
	QCoreApplication::quit();\
}
#endif

#endif