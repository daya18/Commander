#include "CommandPanel.hpp"

#include "Application.hpp"

namespace cmdr
{
    CommandPanel::CommandPanel ()
        : wxFrame ( nullptr, wxID_ANY, "Command Panel", wxDefaultPosition, wxSize ( 300, 500 ) )
    {
        sizer = new wxGridSizer ( 6, 3, { 2, 2 } );

        this->SetSizer ( sizer );

        for ( auto & command : wxGetApp ().GetCommands () )
        {
            auto commandButton { new CommandButton { this, command } };
            sizer->Add ( commandButton, 1, wxEXPAND );
        }

        Layout ();
    }
}