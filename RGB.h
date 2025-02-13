#ifndef RGB_H
#define RGB_H

#include <iostream>
#include <string>
#include "defs.h"
class RGB {
private:
    int r, g, b;

public:
    RGB(int red, int green, int blue);

    RGB(CuColour color);

    RGB();

    CuColour getColour() const;

    void setColour(const CuColour color);

    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();

    int getR() const;
    int getG() const;
    int getB() const;

    void setR(int red);
    void setG(int green);
    void setB(int blue);

    void print() const;
};

#endif