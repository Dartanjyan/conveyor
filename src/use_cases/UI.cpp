#include "UI.h"

UI::UI(IGUI *gui, ICLI *cli) : gui_(gui), cli_(cli) {}

int UI::Run(bool gui)
{
    if (gui)
    {
        if (gui_ == nullptr) {
            std::cerr << "UI.cpp: launched in GUI mode but gui_ is nullptr\n";
            return -1;
        }
        return gui_->Run();
    }
    else
    {
        if (cli_ == nullptr) {
            std::cerr << "UI.cpp: launched in CLI mode but cli_ is nullptr\n";
            return -1;
        }
        return cli_->Run();
    }
}
