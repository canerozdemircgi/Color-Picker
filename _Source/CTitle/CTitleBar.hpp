#pragma once

#include "CCore/CLambda.hpp"
#include "CCore/CStandart.hpp"
#include "CMenu/CMenu.hpp"

#include <QtWidgets/QWidget>

#include <boost/optional.hpp>

using namespace Qt::Literals::StringLiterals;

namespace Ui { class CTitleBar; }

class CPushButtonSta;
class CWidgetsSize;

class CTitleBar final : public QWidget
{
public:
	explicit CTitleBar(QWidget* const parent);
	~CTitleBar() override;

	struct Parameters final
	{
		const cstd::required<const Qt::WindowType> windowType;
		const boost::optional<const QIcon&> icon;
		const std::optional<const CMenu::Parameters> menu;

		const cstd::required<const QString> title;

		const bool atop = false;
		const bool minimize = true;
		const bool maximize = true;
		const bool close = true;

		const bool dispose = true;
	};
	void initialize(const CTitleBar::Parameters& parameters);

	template <CLambda::CCallable<void> Function>
	void addMenuAction(const QString& icon, const QString& text, Function&& function) const;
	CPushButtonSta* addControlButton(const QString& icon, const QString& tooltip, uint8_t index = 0u, bool checkable = false, const QString& tooltipChecked = u""_s) const;

private:
	const Ui::CTitleBar* const ui;
	CMenu* menu;
	CWidgetsSize* const sizeWidgets;

	QRect geometryOriginal;
	QRect getGeometry() const;

friend class CConfiguration;
};