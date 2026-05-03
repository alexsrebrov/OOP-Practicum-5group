#include "Principal.h"
#include <iostream>

std::ostream & operator<<(std::ostream &os, const Principal &person) {
    return os << (UniversityWorker&)person << " room: " << person.room << " pension rate: " << person.pensionRate;
}
