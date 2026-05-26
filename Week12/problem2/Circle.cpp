
#include "Circle.h"

const double PI = 3.14;

Circle::Circle(const std::string &name, const Point &center, const double radius) : Shape(name),center(center),radius(radius){}

double Circle::getPerimeter() const {
    return 2 * PI * radius;
}

double Circle::getArea() const {
    return PI * radius * radius;
}

bool Circle::isPointInside(const Point &p) const {
    return center.distanceTo(p) <= radius;
}

Shape * Circle::clone() const {
    return new Circle(*this);
}
