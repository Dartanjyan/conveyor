#include <iostream>
#include "ApplicationManager.h"
#include "UI.h"
#include "SDLApp.h"
#include "ConsoleApp.h"

int main(int argc, char** argv) {
    ConsoleApp* cli_app = new ConsoleApp();
    auto gui_app = new SDLApp("Sdl works!!!!", 640/2, 480/2);

    // UI takes IGUI and ICLI in its constructor
    std::unique_ptr<UI> ui = std::make_unique<UI>(gui_app, cli_app);

    int result = ApplicationManager::Run(argc, argv, std::move(ui));

    delete gui_app;
    delete cli_app;
    return result;
}
