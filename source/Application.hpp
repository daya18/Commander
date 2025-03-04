#pragma once

#include <wx/wx.h>

#include "Command.hpp"
#include "CommandPanel.hpp"

namespace cmdr
{
    class Application : public wxApp
    {
    public:
        virtual bool OnInit () override;
        
        //void AddCommand ( std::string const & name, std::string const & command );
        void DeleteCommand ( Command & );
        
    private:
        static std::string const dataFilePath;

        void Load ();
        void Save ();
        void CreateDefaultDataFile ();

        std::list <Command> commands;
    };
}

wxDECLARE_APP ( cmdr::Application );