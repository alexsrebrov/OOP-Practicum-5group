#include "GeometricProgression.h"

GeometricProgression::GeometricProgression() : a0(1), q(1) {}
GeometricProgression::GeometricProgression(const int a0, const int q) : a0(a0), q(q) {}

GeometricProgression operator+(const GeometricProgression & lhs, const GeometricProgression & rhs) {
    return GeometricProgression(lhs.a0 + rhs.a0, lhs.q + rhs.q);
}
GeometricProgression operator*(const GeometricProgression & lhs, const GeometricProgression & rhs) {
    return GeometricProgression(lhs.a0 * rhs.a0, lhs.q * rhs.q);
}
int GeometricProgression::operator[](const int index) const {
    int result = a0;
    for (int i = 0; i < index; i++) {
        result *= q;
    }
    return result;
}
int GeometricProgression::operator()(const int index) const {
    if (index == 0) {
        return 0;
    }
    int result = 1;
    int sum = a0;
    for (int i = 1; i < index; i++) {
        result *= q;
        sum += result;
    }
    return sum;
}