#include <iostream>
#include <memory>

#include "Person.h"
using namespace std;

int main() {
    auto person = make_unique<Person>();
    person -> displayPersonInfo();
    auto person2 = std::move(person);
    if (person == nullptr) {
        println("p1 is now nullptr");
    }
    auto person3 = make_shared<Person>();
    auto person4 = person3;
    println("{}", person3.use_count());
}
