#ifndef BASEBUILDING_H
#define BASEBUILDING_H

#include <vector>
#include "Size.h"
#include "Transform.h"
#include "Id.h"

class BaseBuilding {
protected:
    Transform transform;
    Size size;
    Id id;
public:
    BaseBuilding(Transform transform, Size size) : transform(transform), size(size), id(Id("empty")) {}
    BaseBuilding(Transform transform, Size size, Id id) : transform(transform), size(size), id(id) {}
    ~BaseBuilding() = default;

    Transform getTransform() const { return transform; }
    Size getSize() const { return size; }
    Id getId() const { return id; }

    virtual void Act() = 0;
};

#endif
