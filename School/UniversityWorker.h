#ifndef SCHOOL_UNIVERSITYWORKER_H
#define SCHOOL_UNIVERSITYWORKER_H
#include "Person.h"


class UniversityWorker : public Person {
    int workExperience;
    double pension;
    double pensionRate;
public:
    double getPension() const;
    friend std::ostream& operator<<(std::ostream& os, const UniversityWorker& universityWorker);
};


#endif //SCHOOL_UNIVERSITYWORKER_H
