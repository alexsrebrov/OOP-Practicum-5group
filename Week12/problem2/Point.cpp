#include <cmath>
#include "Point.h"

Point::Point(const int x, const int y) : x(x),y(y){}

double Point::distanceTo(const Point &p) const{
    return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
}
