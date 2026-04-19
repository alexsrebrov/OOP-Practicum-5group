#ifndef GEOMETRICPROGRESSION_GEOMETRICPROGRESSION_H
#define GEOMETRICPROGRESSION_GEOMETRICPROGRESSION_H



class GeometricProgression {
    int a0;
    int q;
public:
    GeometricProgression();
    GeometricProgression(int, int);
    friend GeometricProgression operator+(const GeometricProgression&, const GeometricProgression&);
    friend GeometricProgression operator*(const GeometricProgression&, const GeometricProgression&);
    int operator[](int) const;
    int operator()(int) const;
};



#endif //GEOMETRICPROGRESSION_GEOMETRICPROGRESSION_H
