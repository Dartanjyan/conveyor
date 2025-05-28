#pragma once

#include <map>
#include <iostream>
#include <cstdint>

#include "BaseBuilding.h"
#include "Transform.h"
#include "Item.h"
#include "Size.h"

class Conveyor: public BaseBuilding{
private:
    uint8_t level;
    // How far to move items on conveyor each tick
    float movingSpeed = 0.1f;
    // Next conveyor
    Conveyor *next, *left, *right, *back;
    // Map that keeps pointers to objects on the conveyor and their position
    // relatively to the conveyor's position and rotation
    // TODO: Item* should be std::unique_ptr<Item>
    std::map<Item*, Transform> items;
public:
    Conveyor(Transform transform, Size size, uint8_t level);
    
    uint8_t getLevel() const { return level; }

    Conveyor* getNext() const { return next; }
    void setNext(Conveyor* conv) { next = conv; }
    Conveyor* getRight() const { return right; }
    void setRight(Conveyor* conv) { right = conv; }
    Conveyor* getLeft() const { return left; }
    void setLeft(Conveyor* conv) { left = conv; }
    Conveyor* getBack() const { return back; }
    void setBack(Conveyor* conv);
    
    std::map<Item*, Transform> getItems() const { return items; }

    void Act() override;
    // Try to accept item on relative position relPos
    // Returns true if the Item is accepted and false if not.
    // TODO: Item* should be std::unique_ptr<Item>
    bool AcceptItem(Item* item, const Transform& relPos); 
};
