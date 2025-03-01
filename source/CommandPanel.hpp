#pragma once

#include <wx/wx.h>
#include <wx/tglbtn.h>

#include "CommandButton.hpp"
#include "Command.hpp"

namespace cmdr
{
    class CommandPanel : public wxFrame
    {
    public:
        CommandPanel ();

    private:
        std::vector <wxButton *> commandButtons;
        wxGridSizer * sizer;
    };
}