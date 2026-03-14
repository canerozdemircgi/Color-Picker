#include "CConfiguration.hpp"

#include "CCore/CFile.tpp"
#include "CDialog/CDialogInfoWarningError.hpp"
#include "CGui/CGui.hpp"
#include "CPigment/CColorSlot.hpp"
#include "CWindow/CWindowAbout.hpp"
#include "CWindow/CWindowHelp.hpp"
#include "CWindow/CWindowMain.hpp"

#include "../CTitle/ui_CTitleBar.h"
#include "../CWindow/ui_CWindowMain.h"

#include <boost/json.hpp>

void CConfiguration::initialize(CWindowMain* const mainWindow)
{
	QObject::connect(QCoreApplication::instance(), &QCoreApplication::aboutToQuit, [&mainWindow]
	{
		const QRect mainWindowGeometry = mainWindow->ui->TitleBar->getGeometry();
		const CConfiguration::Data data =
		{
			.mainWindow =
			{
				.titleBar =
				{
					.atop = mainWindow->ui->TitleBar->ui->ATop_PushButton->isChecked(),
					.simple = mainWindow->SimpleMode_PushButton->isChecked(),
					.maximize = mainWindow->ui->TitleBar->ui->Maximize_PushButton->isChecked()
				},

				.colorSlots =
				{
					.columns = static_cast<uint8_t>(mainWindow->ui->ColorSlots->instances[0].size()),
					.rows = static_cast<uint8_t>(mainWindow->ui->ColorSlots->instances.size()),
					.x = CColorSlot::SELECTION->xy.first,
					.y = CColorSlot::SELECTION->xy.second
				},

				.width = static_cast<uint16_t>(mainWindowGeometry.width()),
				.height = static_cast<uint16_t>(mainWindowGeometry.height()),
				.x = static_cast<int16_t>(mainWindowGeometry.x()),
				.y = static_cast<int16_t>(mainWindowGeometry.y())
			}
		};

		std::ostringstream ostringstream;
		CConfiguration::prettyPrint(ostringstream, boost::json::value_from(data));
		CFile::writeFile(u"ColorPicker.json"_s, ostringstream.str().c_str());
	});

	CConfiguration::refresh(mainWindow);
}

void CConfiguration::refresh(CWindowMain* const mainWindow, bool reset)
{
	const QByteArray byteArray = [](CWindowMain* const mainWindow, bool reset)
	{
		if (reset)
		{
			QMetaObject::invokeMethod(mainWindow, [](CWindowMain* const mainWindow)
			{
				CDialogInfoWarningError* const infoDialog = new CDialogInfoWarningError(mainWindow, CDialogInfoWarningError::Type::INFO, u"Configuration has been resetted."_s);
				infoDialog->show();
			}, Qt::ConnectionType::QueuedConnection, mainWindow);

			return CFile::readFile<QByteArray>(":/Configuration/ColorPicker.json"_ba);
		}

		return CFile::readResource<QByteArray>(u"Configuration"_s, u"ColorPicker.json"_s);
	}(mainWindow, reset);

	const CConfiguration::Data data = boost::json::value_to<const CConfiguration::Data>(boost::json::parse(byteArray.constData()));

	mainWindow->ui->ColorSlots->initialize(data.mainWindow.colorSlots.columns, data.mainWindow.colorSlots.rows, data.mainWindow.colorSlots.x, data.mainWindow.colorSlots.y);

	mainWindow->SimpleMode_PushButton->setChecked(data.mainWindow.titleBar.simple);
	mainWindow->ui->TitleBar->ui->ATop_PushButton->setChecked(data.mainWindow.titleBar.atop);

	const QRect rectAllScreens = CGui::availableGeometryAllScreens();
	if (const QRect rectMainWindow(data.mainWindow.x, data.mainWindow.y, data.mainWindow.width, data.mainWindow.height); rectAllScreens.contains(rectMainWindow))
		mainWindow->setGeometry(rectMainWindow);
	else
		CGui::setGeometryMinimumCenter(mainWindow);
	mainWindow->ui->TitleBar->ui->Maximize_PushButton->setChecked(data.mainWindow.titleBar.maximize);

	if (reset)
	{
		CGui::setGeometryMinimumCenter(&CWindowAbout::getInstance());
		CGui::setGeometryMinimumCenter(&CWindowHelp::getInstance());
	}
}

void CConfiguration::prettyPrint(std::ostream& ostream, const boost::json::value& json_value, uint8_t level)
{
	switch (json_value.kind())
	{
		case boost::json::kind::object:
		{
			const std::string indent(level, '\t');
			ostream << (indent.empty() ? "" : "\n") << indent << "{\n";
			if (const boost::json::object& json_object = json_value.get_object(); !json_object.empty())
			{
				for (boost::json::object::const_iterator iterator = json_object.begin(); iterator != json_object.end(); ++iterator)
				{
					if (iterator != json_object.begin())
					{
						ostream << ",\n";
						if ((iterator - 1)->value().is_object())
							ostream << '\n';
					}
					ostream << indent << "\t\"" << iterator->key() << '"';
					ostream << (iterator->value().is_object() ? ":" : ": ");
					CConfiguration::prettyPrint(ostream, iterator->value(), level + 1);
				}
			}
			ostream << '\n' << indent << '}';
			break;
		}

		default:
		{
			ostream << boost::json::serialize(json_value);
			break;
		}
	}
}