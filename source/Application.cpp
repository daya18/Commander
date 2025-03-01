#include "Application.hpp"

#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>

namespace cmdr
{
    Application::Application ()
        : wxApp ()
    {
        if ( std::filesystem::exists ( "Commands.json" ) )
        {
            std::ifstream file { "Commands.json" };
            auto commandsJson { nlohmann::json::parse ( file ) };

            for ( auto const & commandJson : commandsJson )
                commands.emplace_back ( Command { commandJson } );
        }
    }

    bool Application::OnInit ()
    {
        CommandPanel * commandPanel = new CommandPanel ();
        commandPanel->Show ( true );
        return true;
    }

    std::vector <Command> const & Application::GetCommands ()
    {
        return commands;
    }

    Command & Application::CreateCommand ( std::string const & name, std::string const & command )
    {
        commands.emplace_back ( Command { name, command } );

        std::ofstream commandsFile { "Commands.json" };
        
        nlohmann::json commandsJson;

        for ( auto const & command : commands )
            commandsJson.emplace_back ( command.ToJSON () );

        commandsFile << std::setw ( 4 ) << commandsJson;

        return commands.back ();
    }
}

wxIMPLEMENT_APP_CONSOLE ( cmdr::Application );