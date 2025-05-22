#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <map>
#include <cstdint>

#include "pos.h"
#include "item.h"
#include "size.h"
#include "enums.h"

class Conveyor {
public:
    Pos pos;
    uint8_t level;
    // Rotation: ROT_SOUTH, ROT_NORTH, ROT_WEST, ROT_EAST
    uint8_t rotation;
    // Next conveyor
    Conveyor* next;
    // Map that keeps pointers to objects on the conveyor and their position
    // relatively to the conveyor's position and rotation
    std::map<Item*, FloatPos> items;
    Size size;
//public:
    Conveyor(Pos pos, uint8_t rotation, uint8_t level, Size size);
    ~Conveyor();
};

/*
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
*/

#endif
