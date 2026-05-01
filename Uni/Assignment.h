#ifndef UNI_ASSIGNMENT_H
#define UNI_ASSIGNMENT_H
#include <iostream>


class Assignment {
    std::string title;
    std::string description;
public:
    friend std::ostream& operator<<(std::ostream& os, const Assignment& assignment);
};


#endif //UNI_ASSIGNMENT_H
