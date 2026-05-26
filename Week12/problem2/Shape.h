#pragma once
#include<string>
#include "Point.h"
class Shape {
    std::string name;
public:
    Shape() = delete;
    Shape(const std::string& name);
    virtual ~Shape() = default;
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    virtual bool isPointInside(const Point& p) const = 0;
    virtual Shape* clone() const =0;
};