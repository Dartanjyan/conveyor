#include <iostream>

#include "SDLApp.h"
#include "time_mgmt.h"
#include "Conveyor.h"
#include "Id.h"
#include "Transform.h"

#define MAX_SCALE 30.0f
#define MIN_SCALE 5.0f
#define DEFAULT_SCALE (MAX_SCALE+MIN_SCALE)/3*2

SDLApp::SDLApp(std::string name, int width, int height) : name(name), width(width), height(height), window(nullptr), renderer(nullptr), scale(DEFAULT_SCALE) {}

SDLApp::~SDLApp() {}

SDL_Rect BuildingToSDLRect(const BaseBuilding* b, float scale = 1) {
    Transform t = b->getTransform();
    Size s = b->getSize();
    SDL_Rect rect = {(int)(t.getX()*scale), (int)(t.getY()*scale), (int)(s.getWidth()*scale), (int)(s.getHeight()*scale)};
    return rect;
}

void drawConveyor(SDL_Renderer* renderer, const Conveyor* conv, float scale) {
    if (conv != nullptr) {
        Transform trans = conv->getTransform();
        Size size = conv->getSize();
        SDL_Rect rect = BuildingToSDLRect(conv, scale);
        
        // std::cout<<"Rect: "<<trans.getX()*scale<<" "<<trans.getY()<<" "<<size.getWidth()<<" "<<size.getHeight()<<", scale = "<<scale<<", conv="<<conv<<"\n";
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &rect);
        
        // Draw direction triangle
        SDL_Point points[4];
        int cx = rect.x + rect.w / 2;
        int cy = rect.y + rect.h / 2;
        int hw = rect.w / 2;
        int hh = rect.h / 2;

        switch (static_cast<int>((trans.getAngle()+90))%360) {
            case 0:
                points[0] = {rect.x + rect.w - 5, cy};  // tip
                points[1] = {rect.x + 5, rect.y + 5};
                points[2] = {rect.x + 5, rect.y + rect.h - 5};
                break;
            case 90:
                points[0] = {cx, rect.y + rect.h - 5};  // tip
                points[1] = {rect.x + 5, rect.y + 5};
                points[2] = {rect.x + rect.w - 5, rect.y + 5};
                break;
            case 180:
                points[0] = {rect.x + 5, cy};  // tip
                points[1] = {rect.x + rect.w - 5, rect.y + 5};
                points[2] = {rect.x + rect.w - 5, rect.y + rect.h - 5};
                break;
            case 270:
                points[0] = {cx, rect.y + 5};  // tip
                points[1] = {rect.x + 5, rect.y + rect.h - 5};
                points[2] = {rect.x + rect.w - 5, rect.y + rect.h - 5};
                break;
            default:
                // Unsupported angle, draw a dot
                points[0] = {cx, cy};
                points[1] = {cx, cy};
                points[2] = {cx, cy};
                break;
        }
        points[3] = points[0]; // Close the triangle
        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
        SDL_RenderDrawLines(renderer, points, 4);
    }
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



