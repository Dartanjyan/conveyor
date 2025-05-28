#ifndef SDLAPP_H
#define SDLAPP_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "IGUI.h"
#include "SpaceManager.h"

#define MAX_SCALE 20.0f
#define MIN_SCALE 5.0f
#define DEFAULT_SCALE (MAX_SCALE+MIN_SCALE)/2

class SDLApp : public IGUI {
    std::string name;
    int width, height;

    void render();

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    std::unique_ptr<SpaceManager> spaceManager;

    float scale = DEFAULT_SCALE;
public:
    SDLApp(std::string name = "SDL2 Application", int width = 800, int height = 600);
    ~SDLApp();

    int Run() override;
    int Init() override;
    void setSpaceManager(std::unique_ptr<SpaceManager> space_manager) override;
};

#endif
