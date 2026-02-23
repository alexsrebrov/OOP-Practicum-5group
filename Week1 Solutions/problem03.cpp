#include<iostream>
#include<cmath>

struct Triangle {
    double sideA,sideB,sideC;
};

namespace TriangleOperations {

    void readTriangle(Triangle& t) {
        std::cin>>t.sideA>>t.sideB>>t.sideC;
    }

    double findAreaOfTriangle(Triangle n) {
        double result;
        double halfP=(n.sideA+n.sideB+n.sideC)/2;
        result=sqrt(halfP*(halfP-n.sideA)*(halfP-n.sideB)*(halfP-n.sideC));
        return result;
    }

    void swap(double& n1,double& n2) {
        n1+=n2;
        n2=n1-n2;
        n1-=n2;
    }

    void SortAreasOfTriangles(double* areas,int n) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n-i-1; ++j) {
                if (areas[j]>areas[j+1]) {
                    swap(areas[j],areas[j+1]);
                }
            }
        }
    }

    void printArray(double* arr,int n) {
        for (int i=0; i<n; ++i) {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main() {
    using namespace TriangleOperations;
    int n;
    std::cin>>n;
    Triangle* triangle=new Triangle[n];
    for (int i=0; i<n; ++i) {
        readTriangle(triangle[i]);
    }
    double* areas = new double[n];
    for (int i=0; i<n; ++i) {
        areas[i]=findAreaOfTriangle(triangle[i]);
    }
    SortAreasOfTriangles(areas,n);
    printArray(areas,n);
    delete[] areas;
    delete[] triangle;
}