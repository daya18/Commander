#pragma once

#include <wx/wx.h>

#include "Command.hpp"

namespace cmdr
{
	class Command;

	class CommandButton : public wxWindow
	{
	public:
		CommandButton ( wxWindow * parent, Command & );

	private:
		void OnContextMenu ( wxContextMenuEvent & );
		void OnMenu ( wxCommandEvent & );

		Command * command;

		wxBoxSizer * sizer;
		wxButton * button;
	};
}