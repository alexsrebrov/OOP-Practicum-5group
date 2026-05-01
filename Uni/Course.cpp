#include "Course.h"

#include <algorithm>
#include <utility>
using namespace std;

Course::Course(std::string name, int year, const Major &major) : name(std::move(name)), year(year), major(major) {}

void Course::enroll(const Student& student) {
    this -> students.push_back(std::make_shared<Student>(student));
}

void Course::showTopN(unsigned n) {
    std::sort(students.begin(), students.end(), [](const std::shared_ptr<Student>& a, const std::shared_ptr<Student>& b) {
        return a -> calcGPA() > b -> calcGPA();
    });
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ". " << students.at(i);
    }
}

void Course::addAssignment(const Assignment& assignment) {
    givenAssignments.push_back(assignment);
}

void Course::addFinalAssignment(const Assignment& fAssign) {
    finalAssignment = std::make_unique<Assignment>(fAssign);
}

std::ostream & operator<<(std::ostream &os, const Course &course) {
    std::string majorStr;
    if (course.major == Major::Software_Engineering) {
        majorStr = "Software Engineering";
    }
    else if (course.major == Major::Computer_Science) {
        majorStr = "Computer Science";
    }
    else if (course.major == Major::Applied_Mathematics) {
        majorStr = "Applied Mathematics";
    }
    else {
        majorStr = "Data Analysis";
    }
    os << course.name << " " << course.year << " " << majorStr << " Students enrolled: " << endl;
    for (const std::shared_ptr<Student>& student: course.students) {
        os << student;
    }
    if (course.finalAssignment != nullptr) {
        os << "Final assignment: " << endl;
        os << course.finalAssignment;
    }
    return os;
}
