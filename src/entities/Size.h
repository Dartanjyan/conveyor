#ifndef SIZE_H
#define SIZE_H

class Size {
    unsigned short width;
    unsigned short height;
public:
    Size(unsigned short w = 0, unsigned short h = 0);
    
    unsigned short getWidth() const { return width; }
    unsigned short getHeight() const { return height; }
};

#endif
