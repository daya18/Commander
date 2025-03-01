#pragma once

#include <wx/wx.h>

#include "CommandPanel.hpp"
#include "Command.hpp"

namespace cmdr
{
    class Application : public wxApp
    {
    public:
        Application ();

        virtual bool OnInit () override;
        
        std::vector <Command> const & GetCommands ();
        Command & CreateCommand ( std::string const & name, std::string const & command );

    private:
        std::vector <Command> commands;
    };
}

wxDECLARE_APP ( cmdr::Application );