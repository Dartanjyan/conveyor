#ifndef SPACE_H
#define SPACE_H

#include <vector>

#include "BaseBuilding.h"

class Space {
private:
    std::vector<BaseBuilding*> buildings;
public:
    Space();

    std::vector<BaseBuilding*> getBuildings() const { return buildings; }

    void addBuilding(BaseBuilding* building);
    void removeBuilding(BaseBuilding* building);

    void Tick();
};

#endif
