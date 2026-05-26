
#include "Triangle.h"

Triangle::Triangle(const std::string &color, const double a, const double b, const double c) : Shape(color),a(a),b(b),c(c){}

double Triangle::getArea() const {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
