#include "RGB.h"

RGB::RGB(int red, int green, int blue): r(red), g(green), b(blue) {}

RGB::RGB(CuColour color){setColour(color);}

RGB::RGB() : r(0), g(0), b(0) {}

CuColour RGB::getColour() const{return (r << 16) | (g << 8) | b;}

void RGB::setColour(CuColour color){
    b = (color & 0xFF);
    g = ((color >> 8) & 0xFF);
    r = ((color >> 16) & 0xFF);
}

RGB RGB::WHITE(){return RGB(255, 255, 255);}
RGB RGB::BLACK(){return RGB(0, 0, 0);}
RGB RGB::RED(){return RGB(255, 0, 0);}
RGB RGB::GREEN(){return RGB(0, 255, 0);}
RGB RGB::BLUE(){return RGB(0, 0, 255);}

int RGB::getR() const{return r;}
int RGB::getG() const{return g;}
int RGB::getB() const{return b;}

void RGB::setR(int red){r = red;}
void RGB::setG(int green){g = green;}
void RGB::setB(int blue){b = blue;}

void RGB::print() const{std::cout << "Red: " << r << ", Green: " << g << ", Blue: " << b<<std::endl;}