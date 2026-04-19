#include "Matrix.h"

Matrix::Matrix(int n) : n(n) {
    matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix() : n(2) {
    matrix = new int*[2];
    for (int i = 0; i < 2; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix & other) {
    this -> n = other.n;
    this -> matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        this -> matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            this -> matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

Matrix & Matrix::operator=(const Matrix & other) {
    if (this != &other) {
        for (int i = 0; i < n; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
        this -> n = other.n;
        this -> matrix = new int*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix operator+(const Matrix &matrix, const Matrix &matrix1) {
    if (matrix.n != matrix1.n) {
        return {};
    }
    Matrix matrix2(matrix.n);
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix1.n; j++) {
            matrix2.matrix[i][j] = matrix1.matrix[i][j] + matrix.matrix[i][j];
        }
    }
    return matrix2;
}

Matrix operator-(const Matrix &matrix, const Matrix &matrix1) {
    if (matrix.n != matrix1.n) {
        return {};
    }
    Matrix matrix2(matrix.n);
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix1.n; j++) {
            matrix2.matrix[i][j] = matrix1.matrix[i][j] - matrix.matrix[i][j];
        }
    }
    return matrix2;
}

Matrix operator*(const Matrix &matrix, int scalar) {
    Matrix matrix1(matrix);
    for (int i = 0; i < matrix1.n; i++) {
        for (int j = 0; j < matrix1.n; j++) {
            matrix1.matrix[i][j] = matrix1.matrix[i][j] * scalar;
        }
    }
    return matrix1;
}

Matrix operator*(int scalar, const Matrix &matrix) {
    Matrix matrix1(matrix);
    for (int i = 0; i < matrix1.n; i++) {
        for (int j = 0; j < matrix1.n; j++) {
            matrix1.matrix[i][j] = matrix1.matrix[i][j] * scalar;
        }
    }
    return matrix1;
}

Matrix operator*(const Matrix &matrix, const Matrix &matrix1) {
    if (matrix.n != matrix1.n) {
        return 0;
    }
    Matrix matrix2(matrix.n);
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            matrix2.matrix[i][j] = 0;
            for (int k = 0; k < matrix.n; k++) {
                matrix2.matrix[i][j] += matrix.matrix[i][k] * matrix1.matrix[k][j];
            }
        }
    }
    return matrix2;
}

std::strong_ordering Matrix::operator<=>(const Matrix & other) const {
    if (this -> n != other.n) {
        return this -> n <=> other.n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != other.matrix[i][j]) {
                return matrix[i][j] <=> other.matrix[i][j];
            }
        }
    }
    return std::strong_ordering::equal;
}

Matrix & Matrix::operator++() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j]++;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp = *this;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j]++;
        }
    }
    return temp;
}
