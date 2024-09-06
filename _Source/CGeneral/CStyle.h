#ifndef CStyle_H
#define CStyle_H

#include <QtGui/QFont>

class CStyle
{
public:
	static const QFont fontTitle;

	static const QString style;
	static const QString styleSheet;

private:
	static std::unique_ptr<const QFont> getFontTitle();
};

#endif