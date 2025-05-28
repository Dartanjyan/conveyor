#include <iostream>
#include "ApplicationManager.h"
#include "UI.h"
#include "SDLApp.h"
#include "ConsoleApp.h"
#include "SpaceManager.h"

int main(int argc, char** argv) {
    ConsoleApp* cli_app = new ConsoleApp();
    SDLApp* gui_app = new SDLApp("Sdl works!!!!", 640/2, 480/2);

    auto ui = std::make_unique<UI>(gui_app, cli_app);
    auto spaceManager = std::make_unique<SpaceManager>();

    int result = ApplicationManager::Run(argc, argv, std::move(ui), std::move(spaceManager));

    delete gui_app;
    delete cli_app;
    return result;
}
