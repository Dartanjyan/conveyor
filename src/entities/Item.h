#ifndef ITEM_H
#define ITEM_H

#include "Size.h"
#include "Id.h"

class Item {
    Id id;
    Size size;
public:
    Item(Id id, Size size = Size(1, 1)) : id(id), size(size) {}
    
    Id getId() const { return id; }
    Size getSize() const { return size; }
};

#endif
