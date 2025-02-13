#include "TextArea.h"

TextArea::TextArea(int x, int y, int width, int height, string id, string label, RGB fill, RGB border){
        dimensions.x = x;
        dimensions.y = y;
        dimensions.width = width;
        dimensions.height = height;
        this->id = id;
        this->text = label;
        this->fill = fill;
        this->border = border;
    }

TextArea::TextArea(int x, int y, int width, int height, string id, string label){
        dimensions.x = x;
        dimensions.y = y;
        dimensions.width = width;
        dimensions.height = height;
        this->id = id;
        this->text = label;
    }

TextArea::TextArea(Rectangle r, string id, string label, RGB fill, RGB border): dimensions(r), id(id), text(label), fill(fill), border(border){}

TextArea::TextArea(Rectangle r, string id, string label): dimensions(r), id(id), text(label){}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y){
    XMapWindow(display, win);
    XFlush(display);
    usleep(100000);

    XSetWindowBackground(display, win, fill.getColour());
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, dimensions.width + x, dimensions.height + y);

    XDrawString(display, win, gc, x + 5, y + dimensions.height / 2, text.c_str(), text.length());

    XFlush(display);
}

bool TextArea::overlaps(TextArea& ta) const{
    if (dimensions.overlaps(ta.getDimensions())) return true;
    return false;
}

void TextArea::print() const{
    std::cout << "TextArea id: " << id << "\nText: " << text<< "\nPreferred Location: " << dimensions.x << ", " << dimensions.y
    << "\nSize: "<< dimensions.width<< ", "<< dimensions.height<<std::endl;

}

Rectangle TextArea::getDimensions() const{return dimensions;}
string TextArea::getText() const{return text;}
string TextArea::getID() const{return id;}
RGB TextArea::getFill() const{return fill;}
RGB TextArea::getBorder() const{return border;}

void TextArea::setDimensions(Rectangle r){dimensions = r;}
void TextArea::setText(string label){text = label;}
void TextArea::setID(string id){this->id = id;}
void TextArea::setFill(RGB fill){this->fill = fill;}
void TextArea::setBorder(RGB border){this->border = border;}