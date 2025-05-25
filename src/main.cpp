#include <iostream>
#include "ApplicationManager.h"
#include "UI.h"
#include "SDLApp.h"
#include "ConsoleApp.h"

int main(int argc, char** argv) {
<<<<<<< HEAD
    auto gui_app = new SDLApp("Sdl works!!!!", 640, 480);
    ConsoleApp* cli_app = new ConsoleApp();
=======
    auto gui_app = new SDLApp("Sdl works!!!!", 640/2, 480/2);
>>>>>>> 8eec206 (Split SDLApp::Init to a separate file in order to speed up compiling)

    // UI takes IGUI and ICLI in its constructor
    std::unique_ptr<UI> ui = std::make_unique<UI>(gui_app, cli_app);

    int result = ApplicationManager::Run(argc, argv, std::move(ui));

    delete gui_app;
    delete cli_app;
    return result;
}
