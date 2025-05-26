#include <iostream>

#include "SDLApp.h"
#include "time_mgmt.h"

SDLApp::SDLApp(std::string name, int width, int height) : name(name), width(width), height(height), window(nullptr), renderer(nullptr) {}

SDLApp::~SDLApp() {}

int SDLApp::Run() {
    if (window == nullptr) {
        std::cout << "Initializing window\n";
        int initialized = this->Init();
        if (initialized != 0) {
            std::cerr << "Couldn't initialize window.\n";
            return -1;
        }
    }

    bool running = true;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        tick(60);
    }

    return 0;
}

