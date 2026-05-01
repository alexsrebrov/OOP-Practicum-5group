#include "Person.h"

#include <iostream>
#include <ostream>

void Person::displayPersonInfo() const {
    println("Name: {}, {} years old", name, age);
}
