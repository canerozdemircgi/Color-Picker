#pragma once

#include <boost/describe/class.hpp>
#include <cstdint>
#include <string_view>

class CWindowMain;

namespace boost::json { class value; }

class CConfiguration final
{
public:
	struct Data final
	{
		struct MainWindow final
		{
			struct TitleBar final
			{
				bool atop;
				bool simple;
				bool maximize;
			};
			TitleBar titleBar;

			struct ColorSlots final
			{
				uint8_t columns;
				uint8_t rows;
				uint8_t x;
				uint8_t y;
			};
			ColorSlots colorSlots;

			uint16_t width;
			uint16_t height;
			int16_t x;
			int16_t y;
		};
		MainWindow mainWindow;
	};

	static void initialize(CWindowMain* const mainWindow);
	static void refresh(CWindowMain* const mainWindow, bool reset = false);

private:
	static void prettyPrint(std::ostream& ostream, const boost::json::value& json_value, uint8_t level = 0);
};

BOOST_DESCRIBE_STRUCT(CConfiguration::Data::MainWindow::TitleBar, (), (atop, simple, maximize));
BOOST_DESCRIBE_STRUCT(CConfiguration::Data::MainWindow::ColorSlots, (), (columns, rows, x, y));
BOOST_DESCRIBE_STRUCT(CConfiguration::Data::MainWindow, (), (titleBar, colorSlots, width, height, x, y));
BOOST_DESCRIBE_STRUCT(CConfiguration::Data, (), (mainWindow));