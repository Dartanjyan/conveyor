#include <iostream>

#include "SDLApp.h"
#include "time_mgmt.h"
#include "Conveyor.h"
#include "Id.h"
#include "Transform.h"

SDLApp::SDLApp(std::string name, int width, int height) : name(name), width(width), height(height), window(nullptr), renderer(nullptr) {}

SDLApp::~SDLApp() {}

SDL_Rect BuildingToSDLRect(const BaseBuilding* b, float scale = 1) {
    Transform t = b->getTransform();
    Size s = b->getSize();
    SDL_Rect rect = {(int)(t.getX()*scale), (int)(t.getY()*scale), (int)(s.getWidth()*scale), (int)(s.getHeight()*scale)};
    return rect;
}

void drawConveyor(SDL_Renderer* renderer, const Conveyor* conv, float scale) {
    Transform transform = conv->getTransform();
    Size size = conv->getSize();
    SDL_Rect rect = BuildingToSDLRect(conv, scale);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

void SDLApp::render() {
    std::vector<const BaseBuilding*> buildings = this->spaceManager->getBuildings();
    // std::cout<<"\e[36mSDLApp.cpp\e[0m: size of buildings vector: "<<buildings.size()<<std::endl;
    for (auto& building : buildings) {
        SDL_Rect buildingRect = BuildingToSDLRect(building);
        SDL_Rect winRect {0, 0, 0, 0};
        SDL_GetWindowSize(this->window, &winRect.w, &winRect.h);

        if(SDL_HasIntersection(&buildingRect, &winRect)) {
            if (building->getId() == Id("conveyor")) {
                drawConveyor(this->renderer, dynamic_cast<const Conveyor*>(building), scale);
            }
        }
    }
}

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

        render();

        SDL_RenderPresent(renderer);
        tick(60);
    }

    return 0;
}



