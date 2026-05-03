#ifndef SCHOOL_PRINCIPAL_H
#define SCHOOL_PRINCIPAL_H
#include "UniversityWorker.h"


class Principal : public UniversityWorker {
    std::string room;
    double pensionRate = 1.5;
public:
    friend std::ostream& operator<<(std::ostream &os, const Principal &person);
};


#endif //SCHOOL_PRINCIPAL_H
