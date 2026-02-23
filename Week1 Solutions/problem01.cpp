#include<iostream>

namespace MatrixNS {

    const int MAX_SIZE=100;

    void swap(int& a,int& b) {
        a+=b;
        b=a-b;
        a-=b;
    }

    void readMatrix(int matrix[][MAX_SIZE],size_t rows,size_t cols) {
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                std::cin>>matrix[i][j];
            }
        }
    }

    void printMatrix(int matrix[][MAX_SIZE],size_t rows,size_t cols) {
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                std::cout<<matrix[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    void transpose(int matrix[][MAX_SIZE],size_t rows,size_t cols) {
        for (int i=0; i<rows; ++i) {
            for (int j=i+1; j<cols; ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    void swapTwoRows(int matrix[][MAX_SIZE],size_t rows,size_t cols,int num1,int num2) {
        for (int i=0; i<cols; ++i) {
            swap(matrix[num1-1][i],matrix[num2-1][i]);
        }
    }
}

int main() {
    using namespace MatrixNS;
    int n,m;
    std::cin>>n>>m;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix,n,m);
    swapTwoRows(matrix,n,m,1,2);
    printMatrix(matrix,n,m);
}