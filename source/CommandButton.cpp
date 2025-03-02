#include "CommandButton.hpp"

namespace cmdr
{
	CommandButton::CommandButton ( wxWindow * parent, Command const & command )
	:
		wxWindow { parent, wxID_ANY },
		sizer { new wxBoxSizer { wxVERTICAL } },
		button { new wxButton { this, wxID_ANY, command.GetName () } },
		command ( command )
	{
		sizer->Add ( button, 1, wxEXPAND );
		button->Bind ( wxEVT_BUTTON, [ this ] ( wxCommandEvent & ) { this->command.Execute (); } );
		SetSizer ( sizer );
	}
}