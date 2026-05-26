#pragma once
struct Point {
    int x,y;
    Point()=delete;
    Point(const int x,const int y);
    double distanceTo(const Point& p) const;
};