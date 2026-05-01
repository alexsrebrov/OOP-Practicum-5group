#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H
#include <__format/range_default_formatter.h>
#include <__fwd/string.h>


class Person {
    std::string name;
    int age;
public:
    void displayPersonInfo() const;
};


#endif //PERSON_PERSON_H
