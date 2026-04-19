#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <compare>


class Matrix {
    int n;
    int** matrix = nullptr;
public:
    Matrix(int);
    Matrix();
    Matrix(const Matrix &);
    ~Matrix();
    Matrix& operator=(const Matrix &);
    friend Matrix operator+(const Matrix &, const Matrix &);
    friend Matrix operator-(const Matrix &, const Matrix &);
    friend Matrix operator*(const Matrix &, int scalar);
    friend Matrix operator*(int scalar, const Matrix &);
    friend Matrix operator*(const Matrix &, const Matrix &);
    std::strong_ordering operator<=>(const Matrix &) const;
    Matrix& operator++();
    Matrix operator++(int);

};



#endif //MATRIX_MATRIX_H
