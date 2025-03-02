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
		~Config ();

		void SetCommandPanelSize ( wxSize const & );
		void SetCommands ( std::vector <Command> const & );

		wxSize GetCommandPanelSize ();
		std::vector <Command> GetCommands ();

		nlohmann::json & GetJson ();

	private:
		nlohmann::json json;
	};



	// Implementation
	inline nlohmann::json & Config::GetJson () { return json; }
}