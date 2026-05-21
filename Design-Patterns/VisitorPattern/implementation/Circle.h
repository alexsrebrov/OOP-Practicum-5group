#pragma once
#include "Shape.h"
#include <algorithm>

class Circle : public Shape {
public:
    double r;
    Circle(double radius) : r(radius) {}

    bool canFitInto(const Shape& outer) const override {
        return outer.fitIntoCircle(*this);
    }

    bool fitIntoCircle(const Circle& c) const override {
        // logic ...
        return false;
    }

    bool fitIntoRectangle(const Rectangle& r) const override {
        // logic ...
        return true;
    }

    bool fitIntoTriangle(const Triangle&) const override {
        // logic ...
        return false;
    }
};
