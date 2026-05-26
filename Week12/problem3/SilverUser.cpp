
#include "SilverUser.h"

SilverUser::SilverUser(const std::string &name, const int id, const std::string &password, const int age,
    const double balance) : User(name,id,password,age,balance){}

User * SilverUser::clone() const {
    return new SilverUser(*this);
}

double SilverUser::getDiscount() const {
    return discount;
}
