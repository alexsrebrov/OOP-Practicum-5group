#ifndef SCHOOL_TEACHER_H
#define SCHOOL_TEACHER_H
#include "UniversityWorker.h"
#include <vector>
#include "Subject.h"


class Teacher : public UniversityWorker {
    std::vector<Subject> subjects;
    double pensionRate = 1;
public:
    friend std::ostream& operator<<(std::ostream &os, const Teacher &teacher);
};

#endif //SCHOOL_TEACHER_H
