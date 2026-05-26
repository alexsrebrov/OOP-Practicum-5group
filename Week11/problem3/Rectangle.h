#pragma once
#include "Shape.h"
class Rectangle : public Shape {
protected:
    int width;
    int length;
public:
    Rectangle(const std::string& color,const int width,const int length);
    int getArea() const;
};