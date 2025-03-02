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
        void OnResize ( wxSizeEvent & );
        
        std::vector <wxButton *> commandButtons;
        wxGridSizer * sizer;
    };
}