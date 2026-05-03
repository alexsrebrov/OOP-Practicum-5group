#include "Person.h"
#include <iostream>

std::ostream & operator<<(std::ostream &os, const Person &person) {
    return os << person.name << ", " << person.age << "years old";
}
