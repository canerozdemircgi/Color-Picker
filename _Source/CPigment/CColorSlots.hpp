#pragma once

#include <QtWidgets/QWidget>

class CColorSlot;

class CColorSlots final : public QWidget
{
public:
	explicit CColorSlots(QWidget* const parent);

private:
	uint8_t columns;
	uint8_t rows;

	std::vector<std::vector<const CColorSlot*>> instances;

	void initialize(uint8_t columns, uint8_t rows, uint8_t x, uint8_t y);

	void removeColumns(uint8_t columns);
	void removeRows(uint8_t rows);
	void addColumns(uint8_t columns);
	void addRows(uint8_t rows);

	static const CColorSlot* createColorSlot(QWidget* const parent, std::pair<const uint8_t, const uint8_t> xy);

	void wheelEvent(QWheelEvent* const event) override;

friend class CConfiguration;
};