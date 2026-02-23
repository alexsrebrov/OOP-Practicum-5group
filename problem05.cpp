#include<iostream>
#include<cmath>

struct Point {
    int x,y;
};

void readPoint(Point& p) {
    std::cin>>p.x>>p.y;
}

void printPoint(Point p) {
    std::cout<<"("<<p.x<<","<<p.y<<")";
    std::cout<<std::endl;
}

double distanceFromPoint0(Point p) {
    double distance;
    distance=sqrt(p.x*p.x+p.y*p.y);
    return distance;
}

double distanceFromTwoPoints(Point a,Point b) {
    double distance;
    distance=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return distance;
}

int findQuadrant(Point p) {
    if (p.x>0 && p.y>0){return 1;}
    if (p.x>0 && p.y<0){return 4;}
    if (p.x<0 && p.y>0){return 2;}
    if (p.x<0 && p.y<0){return 3;}
    return 0;
}

int main() {
    Point a,b;
    readPoint(a);
    readPoint(b);
    printPoint(a);
    printPoint(b);
    double distanceFromAto0=distanceFromPoint0(a);
    double distanceFromBto0=distanceFromPoint0(b);
    std::cout<<distanceFromAto0<<std::endl;
    std::cout<<distanceFromBto0<<std::endl;
    double distanceFromAtoB=distanceFromTwoPoints(a,b);
    std::cout<<distanceFromAtoB<<std::endl;
    int quadrantA=findQuadrant(a);
    int quadrantB=findQuadrant(b);
    std::cout<<"Point A is from "<<quadrantA<<" quadrant"<<std::endl;
    std::cout<<"Point B is from "<<quadrantB<<" quadrant";
}