#include "Triangle.h"

#include <cmath>

double Triangle::getArea() const {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
