#pragma once
#include "Shape.h"
class Triangle : public Shape {
    Point a,b,c;
public:
    Triangle(const std::string& name,const Point& a,const Point& b,const Point& c);
    double getPerimeter() const override;
    double getArea() const override;
    bool isPointInside(const Point& p) const override;
    Shape* clone() const override;
};