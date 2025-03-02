#include "Config.hpp"

#include <fstream>

namespace cmdr
{
	Config::Config ()
	{
		if ( ! std::filesystem::exists ( "Config.json" ) )
		{
			nlohmann::json json
			{
				R"(
					{
					"CommandPanelWidth": 300,
					"CommandPanelHeight": 500,
	
					"Commands": [
						{ "Name": "Command 1", "Command": "" },
						{ "Name": "Command 2", "Command": "" }
					]
					}
				)"_json
			};

			std::ofstream file { "Config.json" };
			file << std::setw ( 4 ) << json;
		}

		std::ifstream file { "Config.json" };
		json = nlohmann::json::parse ( file );
	}

	Config::~Config ()
	{
		std::ofstream file { "Config.json" };
		file << std::setw ( 4 ) << json;
	}

	void Config::SetCommandPanelSize ( wxSize const & size )
	{
		json [ "CommandPanelWidth" ] = size.x;
		json [ "CommandPanelHeight" ] = size.y;
	}

	void Config::SetCommands ( std::vector <Command> const & commands )
	{
		json [ "Commands" ] = "[]"_json;

		for ( int i = 0; auto const & command : commands )
			json [ "Commands" ] [ i++ ] = command.ToJSON ();
	}

	wxSize Config::GetCommandPanelSize ()
	{
		wxSize size;

		size.x = json [ "CommandPanelWidth" ];
		size.y = json [ "CommandPanelHeight" ];

		return size;
	}

	std::vector <Command> Config::GetCommands ()
	{
		std::vector <Command> commands;

		for ( auto & commandJson : json [ "Commands" ] )
			commands.push_back ( Command { commandJson } );

		return commands;
	}
}