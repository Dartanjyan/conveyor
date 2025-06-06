#include <iostream>
#include <string>
#include "SDLApp.h"
#include "Conveyor.h"

int SDLApp::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout<<"Couldn't initialize SDL: " << SDL_GetError() << "\n";
        return -1;
    }
    window = SDL_CreateWindow(
        name.c_str(),
        0,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    if (window == nullptr) {
        std::cout << "Couldn't open a window: " << SDL_GetError() << "\n";
        SDL_Quit();
        return -1;
    }
    std::cout << "Trying to run accelerated renderer...\n";
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if (renderer == nullptr) {
        std::cout << "Couldn't use accelerated rendering (GPU): " << SDL_GetError() << "\nTrying to use software rendering (CPU)...\n";
        renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_SOFTWARE
        );
        if (renderer == nullptr) {
            std::cout << "Couldn't create software renderer: " << SDL_GetError() << "\n";
            SDL_DestroyWindow(window);
            SDL_Quit();
            return -1;
        } else {
            std::cout << "\nUsing software (CPU) rendering.\n\n";
        }
    } else {
        std::cout << "\nUsing accelerated (GPU) rendering.\n\n";
    }
    
    spaceManager->start();

    auto conv = new Conveyor(Transform(0, 0, 0), Size(1, 1), 1);
    conv->AcceptItem(new Item(Id("item")), Transform(0.5f, 0.5f, 0));
    spaceManager->addBuilding(conv);

    return 0;
}

void SDLApp::setSpaceManager(std::unique_ptr<SpaceManager> space_manager) {
    spaceManager = std::move(space_manager);
}

