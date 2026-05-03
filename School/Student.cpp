#include "Student.h"
#include <iostream>

std::ostream & operator<<(std::ostream &os, const Student &student) {
    os << (Person&)student << std::endl;
    for (const auto &[first, second] : student.grades) {
        os << first << " " << second << std::endl;
    }
    return os;
}
