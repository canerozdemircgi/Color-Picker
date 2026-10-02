#pragma once

#include "CWidget/CLabelSvg.hpp"

class CLabelMask;
class CLabelTarget;

class CColorSlot final : public CLabelSvg
{
public:
	explicit CColorSlot(QWidget* const parent, std::pair<const uint8_t, const uint8_t> xy) noexcept;
	static const CColorSlot* getSelection() noexcept;

	void setBackgroundColor(const QColor& color) const noexcept;
	void select() const noexcept;

	const std::pair<const uint8_t, const uint8_t> xy;

private:
	static const CColorSlot* SELECTION;

	QWidget* const Color_Widget;
	CLabelTarget* const Target_Label;
	CLabelMask* const Mask_Label;

	void setSelected(bool selected) const noexcept;

	void mouseReleaseEvent(QMouseEvent* const event) noexcept override;
	void resizeEvent(QResizeEvent* const event) noexcept override;

// friend class CColorSlots;
friend class CConfiguration;
};