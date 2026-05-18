#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
    double w, h;
    Rectangle(double width, double height) : w(width), h(height) {}

    bool canFitInto(const Shape& outer) const override {
        return outer.fitIntoRectangle(*this);
    }

    bool fitIntoCircle(const Circle&) const override {
        // logic ...
        return true;
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
