#ifndef GEOMETRICVECTOR_GEOMETRICVECTOR_H
#define GEOMETRICVECTOR_GEOMETRICVECTOR_H
#include <iosfwd>
using namespace std;


class GeometricVector {
    int* dimension = nullptr;
    int size;
public:
    GeometricVector();
    GeometricVector(int , const int*);
    GeometricVector(const GeometricVector&);
    ~GeometricVector();
    friend GeometricVector operator+(const GeometricVector&, const GeometricVector&);
    friend GeometricVector operator-(const GeometricVector&, const GeometricVector&);
    friend GeometricVector operator*(const GeometricVector&, int);
    friend GeometricVector operator*(int, const GeometricVector&);
    friend int operator*(const GeometricVector&, const GeometricVector&);
    friend GeometricVector operator^(const GeometricVector&, const GeometricVector&);
    friend double operator<(const GeometricVector&, const GeometricVector&);
    double length() const;
    friend ostream& operator<<(ostream&, const GeometricVector&);
    friend istream& operator>>(istream&, GeometricVector&);

};



#endif //GEOMETRICVECTOR_GEOMETRICVECTOR_H
