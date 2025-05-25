#include "Size.h"

Size::Size(unsigned short w, unsigned short h) {
    width = w == 0 ? 1 : w;
    height = h == 0 ? w : h;
}

