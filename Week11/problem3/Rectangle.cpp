
#include "Rectangle.h"

Rectangle::Rectangle(const std::string &color, const int width, const int length) : Shape(color),width(width),length(length){}

int Rectangle::getArea() const {
    return length*width;
}
