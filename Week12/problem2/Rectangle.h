#pragma once
#include "Shape.h"
class Rectangle : public Shape{
    Point a,b,c,d;
public:
    Rectangle(const std::string& name,const Point& a,const Point& b,const Point& c,const Point& d);
    double getPerimeter() const override;
    double getArea() const override;
    bool isPointInside(const Point& p) const override;
    Shape* clone() const override;
};