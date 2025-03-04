#include "CommandButton.hpp"

namespace cmdr
{
	CommandButton::CommandButton ( wxWindow * parent, Command & command )
	:
		wxWindow { parent, wxID_ANY },
		command ( & command ),
		sizer { new wxBoxSizer { wxVERTICAL } },
		button { new wxButton { this, wxID_ANY, command.GetName () } }
	{
		button->Bind ( wxEVT_CONTEXT_MENU, &CommandButton::OnContextMenu, this );
		Bind ( wxEVT_MENU, &CommandButton::OnMenu, this );

		sizer->Add ( button, 1, wxEXPAND );
		button->Bind ( wxEVT_BUTTON, [ this ] ( wxCommandEvent & ) { this->command->Execute (); } );
		SetSizer ( sizer );
	}

	void CommandButton::OnContextMenu ( wxContextMenuEvent & evt )
	{
		wxMenu menu;

		menu.Append ( 1012, "Delete" );
		
		PopupMenu ( & menu );
	}

	void CommandButton::OnMenu ( wxCommandEvent & evt )
	{
		switch ( evt.GetId () )
		{
		case 1012:
			Destroy ();
			break;
		}
	}
}