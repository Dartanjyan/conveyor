#include "Conveyor.h"

Conveyor::Conveyor(Transform transform, Size size, uint8_t level): BaseBuilding(transform, size) {
    switch(level) {
        default:
            this->id = Id("conveyor");
            break;
    }
}
