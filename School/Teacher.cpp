#include "Teacher.h"
#include <iostream>

std::ostream & operator<<(std::ostream &os, const Teacher &teacher) {
    os << (UniversityWorker&)teacher << std::endl;
    for (const auto& subject : teacher.subjects) {
        os << subject << std::endl;
    }
    os << "pension rate: " << teacher.pensionRate << std::endl;
    return os;
}
