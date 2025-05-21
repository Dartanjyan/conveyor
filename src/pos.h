#ifndef POS_H
#define POS_H

#include <stdint.h>

typedef struct Pos {
    uint64_t x, y;
} Pos;

typedef struct FloatPos {
    float x, y;
} FloatPos;

#endif
