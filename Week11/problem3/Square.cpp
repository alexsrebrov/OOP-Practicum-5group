
#include "Square.h"

Square::Square(const std::string &color, const int side) : Rectangle(color,side,side),side(side){}

int Square::getArea() const {
    return side*side;
}
