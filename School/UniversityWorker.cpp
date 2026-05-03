#include "UniversityWorker.h"
#include "iostream"

double UniversityWorker::getPension() const {
    return pension;
}

std::ostream & operator<<(std::ostream &os, const UniversityWorker &universityWorker) {
    return os << (Person&)universityWorker << " " << universityWorker.workExperience << " " << universityWorker.pension << " " << universityWorker.pensionRate;
}
