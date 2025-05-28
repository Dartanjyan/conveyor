#include <iostream>
#include <functional>

#include "SpaceManager.h"

SpaceManager::SpaceManager() : space(std::make_unique<Space>()), running(false) {}

SpaceManager::SpaceManager(std::unique_ptr<Space> space)
    : space(std::move(space)), running(false)
{}


SpaceManager::~SpaceManager() {
    stop();
}

void SpaceManager::start() {
    if (!running.load()) {
        running.store(true);
        space->init();
        spaceThread = std::thread(&SpaceManager::run, this);
        std::cout << "Created new space thread\n";
    } else {
        std::cout << "Space thread already running, no need to create.\n";
    }
}

void SpaceManager::stop() {
    if (running.load()) {
        running.store(false);
        if (spaceThread.joinable())
            spaceThread.join();
        std::cout<<"Space engine has been shut down\n";
    }
}

void SpaceManager::run() {
    // std::cout<<"SpaceManager: run() called!\n";
    using namespace std::chrono;
    
    // Constants for fixed timestep and target frame rate
    constexpr milliseconds TARGET_FRAME_TIME(16); // ~60 FPS (1000ms/60 ≈ 16.66ms)
    auto previous_time = high_resolution_clock::now();
    auto accumulated_lag = 0ms; // Tracks accumulated processing delays

    std::chrono::_V2::system_clock::time_point current_time;
    std::chrono::nanoseconds elapsed_time;

    while (running.load()) {
        // Measure elapsed time since last frame
        current_time = high_resolution_clock::now();
        elapsed_time = current_time - previous_time;
        previous_time = current_time;
        
        space->update();

        // Handle all pending creature additions in this frame
        while (!buildingQueue.empty()) {
            // std::cout<<"SpaceManager.cpp: buildingQueue is not empty so adding building\n";
            space->addBuilding(buildingQueue.front());
            buildingQueue.pop();
        }

        // Update rate regulation
        const auto processing_time = duration_cast<milliseconds>(
            high_resolution_clock::now() - current_time
        );

        // Calculate required sleep time to maintain target frame rate
        const auto sleep_time = TARGET_FRAME_TIME - processing_time;
        // std::cout << sleep_time.count() << " ms" << std::endl;
        if (sleep_time > 0ms) {
            // If we have time left, sleep to maintain consistent frame rate
            std::this_thread::sleep_for(sleep_time);
            // accumulated_lag = 0ms; // Reset lag if we're on schedule
        } else {
            // If we're running behind, accumulate the delay
            // This will reduce sleep time in subsequent frames to catch up
            // accumulated_lag = -sleep_time;
        }
    }
}

std::vector<const BaseBuilding*> SpaceManager::getBuildings() const {
    if (this->space != nullptr) {
        return this->space->getBuildings();
    } else {
        return {nullptr};
    }
}

void SpaceManager::addBuilding(BaseBuilding* building) { 
    // std::cout<<"SpaceManager.cpp: called addBuilding\n";
    buildingQueue.push(building);
}

