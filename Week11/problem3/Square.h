#pragma once
#include "Rectangle.h"
class Square : public Rectangle {
    int side;
public:
    Square(const std::string& color,const int side);
    int getArea() const;
};