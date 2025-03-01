#pragma once

#include <wx/wx.h>

#include "CommandPanel.hpp"
#include "Command.hpp"

namespace cmdr
{
    class Application : public wxApp
    {
    public:
        virtual bool OnInit () override;
        
        std::vector <Command> const & GetCommands ();

    private:
        void CreateDefaultConfigFile ();
        void LoadConfigFromFile ();

        std::vector <Command> commands;
    };



    // Implementation
    inline std::vector <Command> const & Application::GetCommands ()
    {
        return commands;
    }
}
wxDECLARE_APP ( cmdr::Application );