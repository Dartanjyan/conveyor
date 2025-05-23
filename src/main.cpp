#include <iostream>
#include "ApplicationManager.h"
#include "UI.h"
#include "SDLApp.h"

int main(int argc, char** argv) {
    // TODO Create IGUI app (on SDL2)
    auto gui_app = new SDLApp("Sdl works!!!!", 200, 200);

    // UI takes IGUI and ICLI in its constructor
    std::unique_ptr<UI> ui = std::make_unique<UI>(gui_app, nullptr);

    int result = ApplicationManager::Run(argc, argv, std::move(ui));

    return result;
}
