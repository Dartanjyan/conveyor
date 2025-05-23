#ifndef SDLAPP_H
#define SDLAPP_H

#include <string>
#include <SDL2/SDL.h>
#include "IGUI.h"

class SDLApp : public IGUI {
    std::string name;
    int width, height;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
public:
    SDLApp(std::string name = "SDL2 Application", int width = 800, int height = 600);
    ~SDLApp();

    int Run() override;
    int Init() override;
};

#endif
