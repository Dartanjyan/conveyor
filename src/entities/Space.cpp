#include <iostream>

#include "Space.h"

Space::Space() {}

Space::~Space() {
    for (auto& building : buildings) {
        delete building;
    }
}

void Space::init() {
    std::cout << "Space initialized\n";
}

void Space::removeBuilding(BaseBuilding* building) {
    for (size_t i=0; i < buildings.size(); ++i) {
        if (buildings[i] == building) {
            delete buildings[i];
            buildings.erase(buildings.begin()+i);
            break;
        }
    }
}

void Space::addBuilding(BaseBuilding* building) {
    // std::cout<<"Space.cpp: called addBuilding()\n";
    buildings.push_back(building);
}

void Space::update() {
    for (auto& building : buildings) {
        building->Act();
    }
}

std::vector<const BaseBuilding*> Space::getBuildings() const {
    // std::cout<<"Size of original vector: "<<buildings.size()<<", size of new vector: "<<std::vector<const BaseBuilding*>(buildings.begin(), buildings.end()).size()<<"\n";
    return std::vector<const BaseBuilding*>(buildings.begin(), buildings.end());
}

