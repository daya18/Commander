#include "Config.hpp"

#include <fstream>

namespace cmdr
{
	Config::Config ()
	{
		if ( !std::filesystem::exists ( "Config.json" ) )
		{
			SetCommandPanelSize ( { 300, 500 } );
			SetCommands ( { { "Command 1", "" }, {"Command 2", ""} } );
		}
	}

	void Config::SetCommandPanelSize ( wxSize const & size )
	{
		auto json { GetJson () };

		json["CommandPanelWidth"] = size.x;
		json["CommandPanelHeight"] = size.y;
		
		SetJson ( json );
	}

	void Config::SetCommands ( std::vector <Command> const & commands )
	{
		auto json { GetJson () };

		json["Commands"] = "[]"_json;

		for ( int i = 0; auto const & command : commands )
			json["Commands"][i++] = command.ToJSON ();
		
		SetJson ( json );
	}

	wxSize Config::GetCommandPanelSize ()
	{
		wxSize size;
		auto json { GetJson () };

		size.x = json["CommandPanelWidth"];
		size.y = json["CommandPanelHeight"];

		return size;
	}

	std::vector <Command> Config::GetCommands ()
	{
		std::vector <Command> commands;
		auto json { GetJson () };

		for ( auto & commandJson : json["Commands"] )
			commands.push_back ( Command { commandJson } );

		return commands;
	}

	nlohmann::json Config::GetJson ()
	{
		if ( ! std::filesystem::exists ( "Config.json" ) )
			return {};

		std::ifstream file { "Config.json" };
		return nlohmann::json::parse ( file );
	}

	void Config::SetJson ( nlohmann::json const & json )
	{
		std::ofstream file { "Config.json" };
		file << std::setw ( 4 ) << json;
	}
}