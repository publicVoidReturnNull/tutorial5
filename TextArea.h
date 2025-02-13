#ifndef TEXTAREA_H
#define TEXTAREA_H
#include "defs.h"
#include "RGB.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <X11/Xlib.h>

using namespace std;

class TextArea {
private:
    Rectangle dimensions;
    string text;
    string id;
    RGB fill = RGB::WHITE();
    RGB border = RGB::BLACK();

public:
    TextArea(int x, int y, int width, int height, string id, string label, RGB fill, RGB border);
    TextArea(Rectangle r, string id, string label, RGB fill, RGB border); 
    TextArea(Rectangle r, string id, string label); 
    TextArea(int x, int y, int width, int height, string id, string label);

    void draw(Display *display, Window win, GC gc, int x, int y); 

    bool overlaps(TextArea& ta) const;

    void print() const;

    Rectangle getDimensions() const;
    string getText() const;
    string getID() const;
    RGB getFill() const;
    RGB getBorder() const;

    void setDimensions(Rectangle r);
    void setText(string label);
    void setID(string id);
    void setFill(RGB fill);
    void setBorder(RGB border);

};


#endif