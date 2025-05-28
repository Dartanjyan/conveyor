#ifndef ITEM_H
#define ITEM_H

#include "Id.h"

class Item {
    Id id;
    float size;
public:
    Item(Id id, float size = 0.1f) : id(id), size(size) {}
    
    Id getId() const { return id; }
    float getSize() const { return size; }
};

#endif
