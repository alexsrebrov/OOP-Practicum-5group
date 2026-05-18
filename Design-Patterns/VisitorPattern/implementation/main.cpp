#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

bool canInsertInto(const Shape& inner, const Shape& outer) {
    return inner.canFitInto(outer);
}

int main() {
    Circle circle(5);
    Rectangle rectangle(10, 20);
    Triangle triangle(5, 10);

    std::cout << (canInsertInto(circle, rectangle) ? "true" : "false") << '\n';     // true
    std::cout << (canInsertInto(triangle, rectangle) ? "true" : "false") << '\n';   // false
    std::cout << (canInsertInto(rectangle, circle) ? "true" : "false") << '\n';     // true

    return 0;
}