#include "conveyor.h"
#include <stdlib.h>

Conveyor* cgConveyorNew(Pos pos, int rotation, uint8_t level, struct Size size) {
    Conveyor* conv = (Conveyor*)malloc(sizeof(Conveyor));
    if (conv == NULL) {
        return NULL;
    }
    conv->pos = pos;
    conv->rotation = rotation;
    conv->level = level;
    conv->size = size;
}

void cgConveyorFree(Conveyor* conv) {
    free(conv);
}

