#include <iostream>
#include "ApplicationManager.h"
#include "UI.h"
#include "SDLApp.h"
#include "ConsoleApp.h"

int main(int argc, char** argv) {
    auto gui_app = new SDLApp("Sdl works!!!!", 640, 480);
    ConsoleApp* cli_app = new ConsoleApp();

    // UI takes IGUI and ICLI in its constructor
    std::unique_ptr<UI> ui = std::make_unique<UI>(gui_app, cli_app);

    int result = ApplicationManager::Run(argc, argv, std::move(ui));

    delete gui_app;
    delete cli_app;
    return result;
}
