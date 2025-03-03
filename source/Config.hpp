#pragma once

#include <wx/wx.h>
#include <nlohmann/json.hpp>

#include "Command.hpp"

namespace cmdr
{
	class Config
	{
	public:
		Config ();

		void SetCommandPanelSize ( wxSize const & );
		void SetCommands ( std::vector <Command> const & );

		wxSize GetCommandPanelSize ();
		std::vector <Command> GetCommands ();

	private:
		nlohmann::json GetJson ();
		void SetJson ( nlohmann::json const & );
	};
}