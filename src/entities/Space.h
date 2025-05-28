#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <vector>

#include "BaseBuilding.h"

class Space {
private:
    std::vector<BaseBuilding*> buildings;
public:
    Space();
    ~Space();
    
    void init();

    // std::vector<BaseBuilding*> getBuildings() const { return buildings; }

    void addBuilding(BaseBuilding* building);
    void removeBuilding(BaseBuilding* building);

    std::vector<const BaseBuilding*> getBuildings() const;

    void update();
};

#endif
