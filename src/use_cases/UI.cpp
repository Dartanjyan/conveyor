#include "UI.h"

UI::UI(IGUI *gui, ICLI *cli) : gui_(gui), cli_(cli) {}

void UI::setSpaceManager(std::unique_ptr<SpaceManager> space_manager) {
    this->spaceManager = std::move(space_manager);
}

int UI::Run(bool gui)
{
    if (gui)
    {
        if (gui_ == nullptr) {
            std::cerr << "UI.cpp: launched in GUI mode but gui_ is nullptr\n";
            return -1;
        }
        gui_->setSpaceManager(std::move(this->spaceManager));
        return gui_->Run();
    }
    else
    {
        if (cli_ == nullptr) {
            std::cerr << "UI.cpp: launched in CLI mode but cli_ is nullptr\n";
            return -1;
        }
        cli_->setSpaceManager(std::move(this->spaceManager));
        return cli_->Run();
    }
}
