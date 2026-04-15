#pragma once

#include "CWidget/CLabelSvg.hpp"

class CLabelMask;
class CLabelTarget;

class CColorSlot final : public CLabelSvg
{
public:
	explicit CColorSlot(QWidget* const parent, std::pair<const uint8_t, const uint8_t> xy);

	void setBackgroundColor(const QColor& color) const;
	void select() const;

	static const CColorSlot* getSelection();
	const std::pair<const uint8_t, const uint8_t> xy;

private:
	static const CColorSlot* SELECTION;

	QWidget* const Color_Widget;
	CLabelTarget* const Target_Label;
	CLabelMask* const Mask_Label;

	void setSelected(bool selected) const;

	void mouseReleaseEvent(QMouseEvent* const event) override;
	void resizeEvent(QResizeEvent* const event) override;

// friend class CColorSlots;
friend class CConfiguration;
};