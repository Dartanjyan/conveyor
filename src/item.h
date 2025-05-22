#ifndef ITEM_H
#define ITEM_H

#include "size.h"

class Item {
public:
    int id;
    Size size;
    
    Item() : id(1), size(Size(1, 1)) {}
    Item(int id, Size size = Size(1, 1)) : id(id), size(size) {}
    ~Item() {}
};

#endif
