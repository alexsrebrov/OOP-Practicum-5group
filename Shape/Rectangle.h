#ifndef SHAPE_RECTANGLE_H
#define SHAPE_RECTANGLE_H

#include <iostream>

#include "Shape.h"

class Rectangle : public Shape {
    double width;
    double length;
public:
    double getArea() const;
};


#endif //SHAPE_RECTANGLE_H
