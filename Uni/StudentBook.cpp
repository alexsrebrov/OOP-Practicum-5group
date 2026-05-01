#include "StudentBook.h"

void StudentBook::push(double grade) {
    grades.push_back(grade);
}

const std::vector<double> &StudentBook::getGrades() const {
    return grades;
}
