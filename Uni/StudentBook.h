#ifndef UNI_STUDENTBOOK_H
#define UNI_STUDENTBOOK_H
#include <vector>


class StudentBook {
    std::vector<double> grades;
public:
    void push(double grade);
    const std::vector<double>& getGrades() const;
};


#endif //UNI_STUDENTBOOK_H
