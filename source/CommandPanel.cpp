#include "CommandPanel.hpp"

#include "Application.hpp"

namespace cmdr
{
    CommandPanel::CommandPanel ( std::list <Command> & commands )
        : wxFrame ( nullptr, wxID_ANY, "Command Panel" )
    {
        wxMenuBar * menuBar = new wxMenuBar;
        
        wxMenu * fileMenu = new wxMenu ();

        wxMenuItem * addCommandMenuItem = new wxMenuItem ( fileMenu, wxID_ANY, "Add Command");
        fileMenu->Append ( addCommandMenuItem );

        menuBar->Append ( fileMenu, "File" );
        SetMenuBar ( menuBar );

        sizer = new wxGridSizer ( 6, 3, { 2, 2 } );

        this->SetSizer ( sizer );

        for ( auto & command : commands )
        {
            auto commandButton { new CommandButton { this, command } };
            sizer->Add ( commandButton, 1, wxEXPAND );
        }

        Layout ();
    }
}