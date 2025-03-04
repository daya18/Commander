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
        CommandPanel ( std::list <Command> & );

        void SetCommands ( std::list <Command> & );

    private:
        void CreateMenubar ();

        wxGridSizer * sizer;
    };
}