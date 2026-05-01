#ifndef UNI_COURSE_H
#define UNI_COURSE_H
#include <memory>
#include <string>

#include "Assignment.h"
#include "Student.h"

enum class Major {
    Software_Engineering, Computer_Science, Applied_Mathematics, Data_Analysis
};
class Course {
    std::string name;
    int year;
    Major major;
    std::vector<std::shared_ptr<Student>> students;
    std::unique_ptr<Assignment> finalAssignment;
    std::vector<Assignment> givenAssignments;
public:
    Course(std::string  name, int year, const Major& major);
    void enroll(const Student&);
    void showTopN(unsigned n);
    void addAssignment(const Assignment&);
    void addFinalAssignment(const Assignment&);
    friend std::ostream& operator<<(std::ostream& os, const Course& course);
};


#endif //UNI_COURSE_H
