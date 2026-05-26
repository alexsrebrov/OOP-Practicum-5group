
#include "Circle.h"

Circle::Circle(const std::string &color, const double radius) : Shape(color),radius(radius){}

double Circle::getArea() const {
    double pi=3.14;
    return pi*radius*radius;
}
