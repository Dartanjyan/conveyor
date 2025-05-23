#ifndef POS_H
#define POS_H

class Pos {
public:
    int x, y;
    Pos(int x=0, int y=0) : x(x), y(y) {}
};

class FloatPos {
public:
    double x, y;
    FloatPos(double x=0, double y=0): x(x), y(y) {}
};

#endif
