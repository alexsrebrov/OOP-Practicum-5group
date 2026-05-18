#pragma once
#include <iostream>

class Circle;
class Rectangle;
class Triangle;

class Shape {
public:
    virtual bool canFitInto(const Shape& outer) const = 0;

    virtual bool fitIntoCircle(const Circle&) const = 0;
    virtual bool fitIntoRectangle(const Rectangle&) const = 0;
    virtual bool fitIntoTriangle(const Triangle&) const = 0;
    virtual ~Shape() = default;
};
