#include<iostream>

struct ComplexNum {
    double num;
    double ImaginaryPart;
};

namespace ComplexNumbersOperations {

    void readComplexNum(ComplexNum& n) {
        std::cin>>n.num>>n.ImaginaryPart;
    }

    void printComplexNumber(ComplexNum n) {
        if (n.ImaginaryPart>=0) {
            std::cout<<n.num<<" + "<<n.ImaginaryPart<<"i"<<std::endl;
        }
        else {
            std::cout<<n.num<<" "<<n.ImaginaryPart<<"i"<<std::endl;
        }
    }

    ComplexNum ComplexNumbersSum(ComplexNum n1,ComplexNum n2) {
        ComplexNum result;
        result.num=n1.num+n2.num;
        result.ImaginaryPart=n1.ImaginaryPart+n2.ImaginaryPart;
        return result;
    }

    ComplexNum ComplexNumbersMultiplication(ComplexNum n1,ComplexNum n2) {
        ComplexNum result;
        result.num=n1.num*n2.num - n1.ImaginaryPart*n2.ImaginaryPart;
        result.ImaginaryPart=n1.num*n2.ImaginaryPart + n2.num*n1.ImaginaryPart;
        return result;
    }

    ComplexNum ComplexNumbersDivision(ComplexNum n1,ComplexNum n2) {
        ComplexNum result;
        double denominator=n2.num*n2.num + n2.ImaginaryPart*n2.ImaginaryPart;
        result.num=(n1.num*n2.num + n1.ImaginaryPart*n2.ImaginaryPart)/denominator;
        result.ImaginaryPart=(n1.ImaginaryPart*n2.num-n1.num*n2.ImaginaryPart)/denominator;
        return result;
    }
}

int main() {
    using namespace ComplexNumbersOperations;
    ComplexNum n1,n2;
    readComplexNum(n1);
    readComplexNum(n2);
    ComplexNum sum,multiplication,divison;
    sum=ComplexNumbersSum(n1,n2);
    multiplication=ComplexNumbersMultiplication(n1,n2);
    divison=ComplexNumbersDivision(n1,n2);
    printComplexNumber(sum);
    printComplexNumber(multiplication);
    printComplexNumber(divison);
}