
#include "Shape.h"

Shape::Shape(const std::string &color) : color(color){}

const std::string & Shape::getColour() const {
    return color;
}
