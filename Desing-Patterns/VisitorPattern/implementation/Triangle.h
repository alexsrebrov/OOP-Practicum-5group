#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:
    double b, h;
    Triangle(double base, double height) : b(base), h(height) {}
    
    bool canFitInto(const Shape& outer) const override {
        return outer.fitIntoTriangle(*this);
    }

    bool fitIntoCircle(const Circle&) const override {
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
