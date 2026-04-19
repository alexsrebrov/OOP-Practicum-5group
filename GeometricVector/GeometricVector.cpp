#include "GeometricVector.h"

#include <algorithm>
#include <complex>

GeometricVector::GeometricVector() : dimension(new int[3]), size(3) {
    dimension[0] = 0;
    dimension[1] = 0;
    dimension[2] = 0;
}

GeometricVector::GeometricVector(const int size, const int* an) : dimension(new int[size]), size(size) {
    for (int i = 0; i < size; i++) {
        dimension[i] = an[i];
    }
}

GeometricVector::GeometricVector(const GeometricVector & other) : dimension(new int[other.size]), size(other.size) {
    for (int i = 0; i < other.size; i++) {
        this -> dimension[i] = other.dimension[i];
    }
}

GeometricVector::~GeometricVector() {
    delete[] dimension;
}

GeometricVector operator+(const GeometricVector &a, const GeometricVector &b) {
    const int size1 = a.size;
    const int size2 = b.size;
    int* newArray = nullptr;
    if (size1 > size2) {
        newArray = new int[size1];
        for (int i = 0; i < size2; i++) {
            newArray[i] = a.dimension[i] + b.dimension[i];
        }
        for (int i = size2; i < size1; i++) {
            newArray[i] = a.dimension[i];
        }
    }
    else if (size1 < size2) {
        newArray = new int[size2];
        for (int i = 0; i < size1; i++) {
            newArray[i] = a.dimension[i] + b.dimension[i];
        }
        for (int i = size1; i < size2; i++) {
            newArray[i] = b.dimension[i];
        }
    }
    else {
        newArray = new int[size1];
        for (int i = 0; i < size1; i++) {
            newArray[i] = a.dimension[i] + b.dimension[i];
        }
    }
    return GeometricVector(max(size1, size2), newArray);
}

GeometricVector operator-(const GeometricVector &a, const GeometricVector &b) {
    const int size1 = a.size;
    const int size2 = b.size;
    int* newArray = nullptr;
    if (size1 > size2) {
        newArray = new int[size1];
        for (int i = 0; i < size2; i++) {
            newArray[i] = a.dimension[i] - b.dimension[i];
        }
        for (int i = size2; i < size1; i++) {
            newArray[i] = -a.dimension[i];
        }
    }
    else if (size1 < size2) {
        newArray = new int[size2];
        for (int i = 0; i < size1; i++) {
            newArray[i] = a.dimension[i] - b.dimension[i];
        }
        for (int i = size1; i < size2; i++) {
            newArray[i] = -b.dimension[i];
        }
    }
    else {
        newArray = new int[size1];
        for (int i = 0; i < size1; i++) {
            newArray[i] = a.dimension[i] - b.dimension[i];
        }
    }
    return GeometricVector(max(size1, size2), newArray);
}

GeometricVector operator*(const GeometricVector &a, const int scalar) {
    GeometricVector vect(a);
    for (int i = 0; i < vect.size; i++) {
        vect.dimension[i] *= scalar;
    }
    return vect;
}

GeometricVector operator*(const int scalar, const GeometricVector &a) {
    GeometricVector vect(a);
    for (int i = 0; i < vect.size; i++) {
        vect.dimension[i] *= scalar;
    }
    return vect;
}

int operator*(const GeometricVector &a, const GeometricVector &b) {
    int sum = 0;
    const int end = min(a.size, b.size);
    for (int i = 0; i < end; i++) {
        sum += a.dimension[i] * b.dimension[i];
    }
    return sum;
}

GeometricVector operator^(const GeometricVector &a, const GeometricVector &b) {
    if (a.size != 3 || b.size != 3) {
        return {};
    }
    const int first_coordinate = a.dimension[1] * b.dimension[2] - a.dimension[2] * b.dimension[1];
    const int second_coordinate = a.dimension[2] * b.dimension[0] - a.dimension[0] * b.dimension[2];
    const int third_coordinate = a.dimension[0] * b.dimension[1] - a.dimension[1] * b.dimension[0];
    return GeometricVector(3, new int[3]{first_coordinate, second_coordinate, third_coordinate});
}

double operator<(const GeometricVector &a, const GeometricVector &b) {
    return a * b / (a.length() * b.length());
}

double GeometricVector::length() const {
    double l = 0;
    for (int i = 0; i < size; i++) {
        l += this -> dimension[i] * this -> dimension[i];
    }
    return sqrt(l);
}

ostream & operator<<(ostream & os, const GeometricVector & a) {
    os << "(";
    for (int i = 0; i < a.size; i++) {
        os << a.dimension[i];
        if (i != a.size - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

istream & operator>>(istream & is, GeometricVector & a) {
    for (int i = 0; i < a.size; i++) {
        is >> a.dimension[i];
    }
    return is;
}
