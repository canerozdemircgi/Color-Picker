#include "CColorSlots.hpp"

#include "CGui/CColor.hpp"
#include "CPigment/CColorSlot.hpp"

#include <QtWidgets/QHBoxLayout>

CColorSlots::CColorSlots(QWidget* const parent) :
	QWidget{parent},

	columns{0u},
	rows{0u}
{
}

void CColorSlots::initialize(uint8_t columns, uint8_t rows, uint8_t x, uint8_t y)
{
	this->setUpdatesEnabled(false);

	if (this->rows > rows)
	{
		this->removeRows(rows);
		this->rows = rows;
	}
	else if (this->rows < rows)
	{
		this->addRows(rows);
		this->rows = rows;
	}

	if (this->columns > columns)
	{
		this->removeColumns(columns);
		this->columns = columns;
	}
	else if (this->columns < columns)
	{
		this->addColumns(columns);
		this->columns = columns;
	}

	this->instances[y][x]->select();

	this->setUpdatesEnabled(true);
}

void CColorSlots::removeColumns(uint8_t columns)
{
	for (uint8_t y = 0u; y < this->rows; ++y)
	{
		for (uint8_t x = columns; x < this->columns; ++x)
			delete this->instances[y][x];
		this->instances[y].resize(columns);
	}
}

void CColorSlots::removeRows(uint8_t rows)
{
	for (uint8_t y = rows; y < this->rows; ++y)
		delete this->layout()->itemAt(rows)->widget();
	this->instances.resize(rows);
}

void CColorSlots::addColumns(uint8_t columns)
{
	for (uint8_t y = 0u; y < this->rows; ++y)
	{
		QWidget* const hWidget = this->layout()->itemAt(y)->widget();

		this->instances[y].resize(columns);
		for (uint8_t x = this->columns; x < columns; ++x)
			this->instances[y][x] = CColorSlots::createColorSlot(hWidget, {x, y});
	}
}

void CColorSlots::addRows(uint8_t rows)
{
	this->instances.resize(rows);

	for (uint8_t y = this->rows; y < rows; ++y)
	{
		QWidget* const hWidget = new QWidget(this);
		QHBoxLayout* const hLayout = new QHBoxLayout(hWidget);
		hLayout->setContentsMargins(0, 0, 0, 0);
		hLayout->setSpacing(0);
		this->layout()->addWidget(hWidget);

		this->instances[y].resize(this->columns);
		for (uint8_t x = 0u; x < this->columns; ++x)
			this->instances[y][x] = CColorSlots::createColorSlot(hWidget, {x, y});
	}
}

const CColorSlot* CColorSlots::createColorSlot(QWidget* const parent, std::pair<const uint8_t, const uint8_t> xy)
{
	CColorSlot* const colorSlot = new CColorSlot(parent, xy);
	colorSlot->setBackgroundColor(CColor::randomColor(CColor::Spec::RGB, {0u, 255u}, {0u, 255u}, {0u, 255u}, {128u, 255u}));
	parent->layout()->addWidget(colorSlot);
	return colorSlot;
}

void CColorSlots::wheelEvent(QWheelEvent* const event)
{
	// const auto [i, j] = CColorSlot::SELECTION;
	QWidget::wheelEvent(event);
}