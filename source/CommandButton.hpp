#pragma once

#include <wx/wx.h>

namespace cmdr
{
	class Command;

	class CommandButton : public wxWindow
	{
	public:
		CommandButton ( wxWindow * parent, Command const & label );

	private:
		wxBoxSizer * sizer;
		wxButton * button;
		Command const * command;
	};
}