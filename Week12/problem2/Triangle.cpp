#include<cmath>
#include "Triangle.h"

Triangle::Triangle(const std::string &name, const Point &a, const Point &b, const Point &c) : Shape(name),a(a),b(b),c(c) {}

double Triangle::getPerimeter() const {
    double sideA=a.distanceTo(b);
    double sideB=b.distanceTo(c);
    double sideC=c.distanceTo(a);
    return sideA+sideB+sideC;
}

double Triangle::getArea() const {
    double sideA = a.distanceTo(b);
    double sideB = b.distanceTo(c);
    double sideC = c.distanceTo(a);
    double p = (sideA + sideB + sideC) / 2;
    return sqrt(p*(p - sideA)*(p - sideB)*(p - sideC));
}

bool Triangle::isPointInside(const Point &p) const {
    double d1 = (p.x - b.x) * (a.y - b.y) -
                (a.x - b.x) * (p.y - b.y);

    double d2 = (p.x - c.x) * (b.y - c.y) -
                (b.x - c.x) * (p.y - c.y);

    double d3 = (p.x - a.x) * (c.y - a.y) -
                (c.x - a.x) * (p.y - a.y);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}

Shape * Triangle::clone() const {
    return new Triangle(*this);
}
