#ifndef SPACE_MANAGER_H
#define SPACE_MANAGER_H

#include <memory>
#include <thread>
#include <atomic>
#include <queue>
#include <iostream>

#include "Space.h"
#include "BaseBuilding.h"

class SpaceManager {
private:
    void run();
    
    std::unique_ptr<Space> space;

    std::queue<BaseBuilding*> buildingQueue;
    
    std::thread spaceThread;
    std::atomic<bool> running;
public:
    SpaceManager();
    SpaceManager(std::unique_ptr<Space> space);
    ~SpaceManager();

    // simulation thread
    void start();
    void stop();

    void addBuilding(BaseBuilding* building);
    std::vector<const BaseBuilding*> getBuildings() const;
};

#endif
