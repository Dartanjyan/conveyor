#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <map>

#include "pos.h"
#include "item.h"
#include "size.h"
#include "enums.h"

class Conveyor {
private:
    Pos pos;
    byte level;
    byte rotation;
    Conveyor* next;
    std::map<Item*, FloatPos> items;
    Size size;
public:
    Conveyor(Pos pos, int rotation, byte level, Size size);
    ~Conveyor();
    //TODO code constructor
};

typedef struct Conveyor {
    Pos pos;
    uint8_t level;
    // Rotation: ROT_SOUTH, ROT_NORTH, ROT_WEST, ROT_EAST
    int rotation;
    // Next conveyor
    struct Conveyor *next;
    // Array of structures that represent every item on the conveyor
    // and its position on conveyor relative to the conveyor's coordinates and
    // rotation
    struct ItemPosPairs *item;
    // Amount of items on conveyor
    int items;
    // Size of the coneyor. For example 2x2 cells
    struct Size size;
} Conveyor;

Conveyor* cgConveyorNew(Pos pos, int rotation, uint8_t level, struct Size size);
void cgConveyorFree(Conveyor* conv);

#endif
