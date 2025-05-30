#include "ApplicationManager.h"

int ApplicationManager::Run(int argc, char** argv, std::unique_ptr<UI> ui, std::unique_ptr<SpaceManager> space_manager) {
    /*
    * Parse cli flags and arguments and run a UI
    * which further decide what to use: GUI or CLI.
    *
    * This is called from main.cpp
    *
    * IUI is an interface that has a Run function and
    * takes as a Constructor arguments IGUI, ICLI.
    * 
    */

    bool gui = true;
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--nogui") {
            gui = false;
            break;
        }
    }
    
    ui->setSpaceManager(std::move(space_manager));
    int result = ui->Run(gui);
    return result;
}
