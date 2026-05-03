#ifndef SCHOOL_STUDENT_H
#define SCHOOL_STUDENT_H
#include <vector>

#include "Person.h"
#include "Subject.h"


class Student : public Person {
    std::vector<std::pair<Subject, double>> grades;
public:
    friend std::ostream& operator<<(std::ostream &os, const Student &student);
};


#endif //SCHOOL_STUDENT_H
