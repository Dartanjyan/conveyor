#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform {
    float x, y, angle;
public:
    Transform() {}
    Transform(float x, float y, float angle) : x(x), y(y), angle(angle) {}
    Transform(const Transform &other) : x(other.x), y(other.y), angle(other.angle) {}

    float getX() const { return x; }
    float getY() const { return y; }
    float getAngle() const { return angle; }
};

#endif
