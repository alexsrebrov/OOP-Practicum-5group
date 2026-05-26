#pragma once
#include "Shape.h"
class Circle: public Shape {
    double radius;
public:
    Circle(const std::string& color,const double radius);
    double getArea() const;
};