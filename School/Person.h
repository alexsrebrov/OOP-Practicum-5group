#ifndef SCHOOL_PERSON_H
#define SCHOOL_PERSON_H
#include <string>

class Person {
    std::string name;
    int age;
public:
    friend std::ostream& operator<<(std::ostream &os, const Person &person);
};


#endif //SCHOOL_PERSON_H
