#pragma once

#include <wx/wx.h>

#include "Config.hpp"
#include "CommandPanel.hpp"
#include "Command.hpp"

namespace cmdr
{
    class Application : public wxApp
    {
    public:
        virtual bool OnInit () override;
        
        Config & GetConfig ();

    private:
        Config config;
    };



    // Implementation
    inline Config & Application::GetConfig () { return config; }
}
wxDECLARE_APP ( cmdr::Application );