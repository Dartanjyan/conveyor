#ifndef BASEBUILDING_H
#define BASEBUILDING_H

#include <vector>
#include "size.h"
#include "pos.h"

class BaseBuilding {
    Pos pos;
    Size size;
public:
    BaseBuilding(Pos pos, Size size) : pos(pos), size(size) {}

    Pos getPos() const { return pos; }
    Size getSize() const { return size; }
};

#endif
