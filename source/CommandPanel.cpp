#include "CommandPanel.hpp"

#include "Application.hpp"

namespace cmdr
{
    CommandPanel::CommandPanel ()
        : wxFrame ( nullptr, wxID_ANY, "Command Panel", wxDefaultPosition, 
            wxGetApp().GetConfig().GetCommandPanelSize () )
    {
        Bind ( wxEVT_SIZE, &CommandPanel::OnResize, this );

        sizer = new wxGridSizer ( 6, 3, { 2, 2 } );

        this->SetSizer ( sizer );

        for ( auto command : wxGetApp ().GetConfig().GetCommands () )
        {
            auto commandButton { new CommandButton { this, command } };
            sizer->Add ( commandButton, 1, wxEXPAND );
        }

        Layout ();
    }

    void CommandPanel::OnResize ( wxSizeEvent & )
    {
        wxGetApp ().GetConfig ().SetCommandPanelSize ( GetSize () );
    }
}