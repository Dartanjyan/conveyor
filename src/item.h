#ifndef ITEM_H
#define ITEM_H

#include "size.h"
#include "pos.h"

typedef struct Item {
    int id;
    struct Size size;
} Item;

typedef struct ItemPosPair {
    Item* item;

    // Relative float x and y.
    // On conveyor X and Y axis will be the same as screen X and Y if 
    // conveyor looks towards to DIR_NORTH
    FloatPos pos;
} ItemPosPair;
#endif
