#ifndef SIZE_H
#define SIZE_H

#include <cstdint>

class Size {
public:
    uint8_t width;
    uint8_t height;

    Size (uint8_t width = 0, uint8_t height = 0);
};

#endif
