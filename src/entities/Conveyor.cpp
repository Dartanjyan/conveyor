#include <math.h>

#include "Conveyor.h"

Conveyor::Conveyor(Transform transform, Size size, uint8_t level): BaseBuilding(transform, size) {
    switch(level) {
        default:
            this->id = Id("conveyor");
            break;
    }
}

// Try to accept item Item, which comes to position relPos
bool Conveyor::AcceptItem(Item* item, const Transform& relPos) {
    // Check conveyor dimensions
    if (relPos.getX() < 0 || relPos.getX() > getSize().getWidth() ||
        relPos.getY() < 0 || relPos.getY() > getSize().getHeight())
    {
        return false;
    }
    // Check for intersections with already laying items
    for (auto& kv : items) {
        const Transform& otherPos = kv.second;
        const float dx = otherPos.getX() - relPos.getX();
        const float dy = otherPos.getY() - relPos.getY();
        const float dist2 = dx*dx + dy*dy;
        const float minDist = (item->getSize().getWidth() + kv.first->getSize().getWidth()) * 0.5f;
        if (dist2 < minDist*minDist) {
            return false;
        }
    }
    // If the place is free then accept item
    items[item] = relPos;
    return true;
}

void Conveyor::Act() {
    // Move all the items forward
    std::map<Item*, Transform> newPositions;
    for (auto& kv : items) {
        Item* item = kv.first;
        // angle 0 is X positive
        // 90 is Y positive
        // 180 is X negative
        // 270 is Y negative
        const float angleRadians = kv.second.getAngle() * (M_PI / 180);
        const float newX = kv.second.getX() + movingSpeed*cos(angleRadians);
        const float newY = kv.second.getY() + movingSpeed*sin(angleRadians);
        newPositions[item] = Transform(newX, newY, kv.second.getAngle());
    }

    items.clear();

    // Теперь пытаемся либо сохранить на текущем конвейере, либо передать дальше
    for (auto& kv : newPositions) {
        Item* item = kv.first;
        Transform pos = kv.second;

        bool handedOff = false;
        // если вышли за конец конвейера
        if (pos.getX() > getSize().getWidth() && next) {
            // переводим в систему координат next-конвейера
            Transform relPosToNext(
                pos.getX() - getSize().getWidth(),
                pos.getY(),
                pos.getAngle()
            );
            if (next->AcceptItem(item, relPosToNext)) {
                handedOff = true;
            }
        }
        // иначе либо нет next, либо не получилось передать —
        // проверяем, можно ли оставить на текущем конвейере (до самого конца)
        if (!handedOff) {
            // если пытаются уехать «в никуда», оставляем на краю
            float cappedX = std::min(pos.getX(), (float)getSize().getWidth());
            items[item] = Transform(cappedX, pos.getY(), pos.getAngle());
        }
    }

    // Если конвейер никуда не ведёт (next == nullptr), то предметы
    // у задней стенки будут «уплотняться»: при попытке двигаться дальше
    // они просто прижимаются друг к другу (мы уже это сделали, капнув X).
}

