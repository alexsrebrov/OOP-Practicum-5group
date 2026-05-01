#include "Assignment.h"

std::ostream & operator<<(std::ostream &os, const Assignment& assignment) {
    return os << assignment.title << " " << assignment.description;
}
