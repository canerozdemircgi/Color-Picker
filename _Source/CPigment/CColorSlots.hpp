#pragma once

#include <QtWidgets/QWidget>

class CColorSlot;

class CColorSlots final : public QWidget
{
public:
	explicit CColorSlots(QWidget* const parent) noexcept;

private:
	uint8_t columns;
	uint8_t rows;

	std::vector<std::vector<const CColorSlot*>> instances;

	void initialize(uint8_t columns, uint8_t rows, uint8_t x, uint8_t y) noexcept;

	void removeColumns(uint8_t columns) noexcept;
	void removeRows(uint8_t rows) noexcept;
	void addColumns(uint8_t columns) noexcept;
	void addRows(uint8_t rows) noexcept;

	static const CColorSlot* createColorSlot(QWidget* const parent, std::pair<const uint8_t, const uint8_t> xy) noexcept;

	void wheelEvent(QWheelEvent* const event) noexcept override;

friend class CConfiguration;
};