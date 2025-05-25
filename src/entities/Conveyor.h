#pragma once

#include <map>
#include <cstdint>

#include "BaseBuilding.h"
#include "Transform.h"
#include "Item.h"
#include "Size.h"

class Conveyor: public BaseBuilding{
private:
    uint8_t level;
    // Next conveyor
    Conveyor* next;
    // Map that keeps pointers to objects on the conveyor and their position
    // relatively to the conveyor's position and rotation
    std::map<Item*, Transform> items;
public:
    Conveyor(Transform transform, Size size, uint8_t level);
    
    Transform getTransform() const { return transform; }
    uint8_t getLevel() const { return level; }
    const Conveyor* getNextConveyor() const { return next; }
    std::map<Item*, Transform> getItems() const { return items; }
};
