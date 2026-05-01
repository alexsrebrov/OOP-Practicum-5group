#include "Student.h"

#include <ostream>
#include <utility>

static int nextId = 1;
Student::Student(std::string name) : fn(nextId++), name(std::move(name)) {};

void Student::addGrade(double grade) {
    this -> studentBook.push(grade);
}

double Student::calcGPA() const{
    double gpa = 0;
    for (double grade : studentBook.getGrades()) {
        gpa += grade;
    }
    return gpa / studentBook.getGrades().size();
}

std::ostream & operator<<(std::ostream &os, const Student& student) {
    return os << student.name << " " << student.fn;
}

auto Student::operator<=>(const Student& other)const {
    return this -> calcGPA() <=> other.calcGPA();
}
