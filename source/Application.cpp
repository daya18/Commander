#include "Application.hpp"

#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>

namespace cmdr
{
    bool Application::OnInit ()
    {
        CommandPanel * commandPanel = new CommandPanel ();
        commandPanel->Show ( true );
        return true;
    }
}

wxIMPLEMENT_APP_CONSOLE ( cmdr::Application );