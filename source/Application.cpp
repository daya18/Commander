#include "Application.hpp"

#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>

namespace cmdr
{
    std::string const Application::dataFilePath { "data.json" };

    bool Application::OnInit ()
    {
        if ( !std::filesystem::exists ( dataFilePath ) )
            CreateDefaultDataFile ();

        Load ();

        CommandPanel * commandPanel = new CommandPanel ( commands );
        commandPanel->Show ( true );

        return true;
    }

    //void Application::AddCommand ( std::string const & name, std::string const & command )
    //{

    //}

    void Application::DeleteCommand ( Command & targetCommand )
    {
        std::erase_if ( commands, [ &targetCommand ] ( Command const & command ) 
            { return &command == &targetCommand; } );
        
        Save ();
    }
    
    void Application::Load ()
    {
        std::ifstream file { dataFilePath };
        nlohmann::json json { nlohmann::json::parse ( file ) };

        for ( auto const & commandJson : json.at ( "Commands" ) )
        {
            std::string name { commandJson.at ( "Name" ) };
            std::string command { commandJson.at ( "Command" ) };

            commands.emplace_back ( Command { name, command } );
        }
    }

    void Application::Save ()
    {
        nlohmann::json json;
        
        json["Commands"] = nlohmann::json::array ();

        for ( auto const & command : commands )
        {
            nlohmann::json commandJson;

            commandJson["Name"] = command.GetName ();
            commandJson["Command"] = command.GetCommand ();

            json.at ( "Commands" ).push_back ( commandJson );
        }

        std::ofstream file { dataFilePath };
        file << std::setw ( 4 ) << json;
    }

    void Application::CreateDefaultDataFile ()
    {
        nlohmann::json json;

        json["Commands"][0]["Name"] = "Command 1";
        json["Commands"][0]["Command"] = "";

        std::ofstream file { dataFilePath };
        file << std::setw ( 4 ) << json;
    }
}

wxIMPLEMENT_APP_CONSOLE ( cmdr::Application );