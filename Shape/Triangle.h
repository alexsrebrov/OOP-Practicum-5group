#ifndef SHAPE_TRIANGLE_H
#define SHAPE_TRIANGLE_H
#include "Shape.h"


class Triangle : public Shape {
    double a;
    double b;
    double c;
public:
    double getArea() const;
};


#endif //SHAPE_TRIANGLE_H
