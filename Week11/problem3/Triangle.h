#pragma once
#include "Shape.h"
class Triangle : public Shape {
    double a;
    double b;
    double c;
public:
    Triangle(const std::string& color,const double a,const double b,const double c);
    double getArea() const;
};