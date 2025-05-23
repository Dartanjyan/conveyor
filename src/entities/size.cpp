#include "size.h"

Size::Size(uint8_t w, uint8_t h) {
    width = w == 0 ? 1 : w;
    height = h == 0 ? w : h;
}

