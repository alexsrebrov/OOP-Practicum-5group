
#include "Square.h"

Square::Square(const std::string &name, const Point &a, const Point &b, const Point &c, const Point &d) : Shape(name),a(a),b(b),c(c),d(d){}

double Square::getPerimeter() const {
    double side=a.distanceTo(b);
    return side*4;
}

double Square::getArea() const {
    double side=a.distanceTo(b);
    return side*side;
}

bool Square::isPointInside(const Point &p) const {
    double d1 = (p.x - b.x) * (a.y - b.y) -
                (a.x - b.x) * (p.y - b.y);

    double d2 = (p.x - c.x) * (b.y - c.y) -
                (b.x - c.x) * (p.y - c.y);

    double d3 = (p.x - d.x) * (c.y - d.y) -
                (c.x - d.x) * (p.y - d.y);

    double d4 = (p.x - a.x) * (d.y - a.y) -
                (d.x - a.x) * (p.y - a.y);

    bool hasNeg = (d1 < 0) || (d2 < 0) ||
                  (d3 < 0) || (d4 < 0);

    bool hasPos = (d1 > 0) || (d2 > 0) ||
                  (d3 > 0) || (d4 > 0);

    return !(hasNeg && hasPos);
}

Shape * Square::clone() const {
    return new Square(*this);
}
