#ifndef UNI_STUDENT_H
#define UNI_STUDENT_H
#include <string>

#include "StudentBook.h"


class Student {
    int fn;
    std::string name;
    StudentBook studentBook;
public:
    Student(std::string name);
    void addGrade(double grade);
    double calcGPA() const;
    friend std::ostream& operator<<(std::ostream&, const Student&);
    auto operator<=>(const Student&) const;
    Student() = delete;
};


#endif //UNI_STUDENT_H
