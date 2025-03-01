#include "Application.hpp"

#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>

namespace cmdr
{
    bool Application::OnInit ()
    {
        if ( !std::filesystem::exists ( "Commands.json" ) )
            CreateDefaultConfigFile ();
        
        LoadConfigFromFile ();

        CommandPanel * commandPanel = new CommandPanel ();
        commandPanel->Show ( true );
        return true;
    }

    void Application::CreateDefaultConfigFile ()
    {
        std::ofstream file { "Config.json" };
        
        file << std::setw ( 4 ) << R"(
            {
                "Commands": [
                {
                    "Command": "",
                    "Name": "Command 1"
                },
                {
                    "Command": "",
                    "Name": "Command 2"
                },
                {
                    "Command": "",
                    "Name": "Command 3"
                },
                {
                    "Command": "",
                    "Name": "Command 4"
                },
                {
                    "Command": "",
                    "Name": "Command 5"
                }
                ]
            }
        )"_json;
    }

    void Application::LoadConfigFromFile ()
    {
        std::ifstream file { "Config.json" };
        auto commandsJson { nlohmann::json::parse ( file ) };

        for ( auto const & commandJson : commandsJson ["Commands"] )
            commands.emplace_back ( Command { commandJson } );
    }
}

wxIMPLEMENT_APP_CONSOLE ( cmdr::Application );