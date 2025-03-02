#pragma once

#include <wx/wx.h>

#include "Command.hpp"

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
		Command command;
	};
}