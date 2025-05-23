#include "UI.h"

UI::UI(IGUI *gui, ICLI *cli) : gui_(gui), cli_(cli)
{
    // if (gui_ == nullptr || cli_ == nullptr)
    // {
    //     std::clog << "Warning! GUI or CLI is nullptr\n";
    // }
}

UI::~UI()
{
    // No need to clear
    // gui_, cli_, physicsManager will be cleared in main.cpp
}

int UI::Run(bool gui)
{
    if (gui)
    {
        if (gui_ == nullptr) {
            std::cerr << "UI.cpp: launching in GUI mode but gui_ is nullptr\n";
            return -1;
        }
        return gui_->Run();
    }
    else
    {
        if (cli_ == nullptr) {
            std::cerr << "UI.cpp: launching in CLI mode but cli_ is nullptr\n";
            return -1;
        }
        return cli_->Run();
    }
}
