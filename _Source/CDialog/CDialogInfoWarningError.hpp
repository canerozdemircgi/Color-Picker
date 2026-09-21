#pragma once

#include "CDialog/CDialogOk.hpp"

class CDialogInfoWarningError final : private CDialogOk
{
public:
	class Type final
	{
	public:
		static const Type INFO;
		static const Type WARNING;

		const QString name;
		const QIcon icon;
	};
	explicit CDialogInfoWarningError(QWidget* const parent, const CDialogInfoWarningError::Type& type, const QString& content);

	using CDialogOk::show;
};