#pragma once
#include "Shape.h"
class Circle : public Shape{
    Point center;
    double radius;
public:
    Circle(const std::string& name,const Point& center,const double radius);
    double getPerimeter() const override;
    double getArea() const override;
    bool isPointInside(const Point& p) const override;
    Shape* clone() const override;
};