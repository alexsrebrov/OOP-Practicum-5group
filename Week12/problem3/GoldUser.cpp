
#include "GoldUser.h"

GoldUser::GoldUser(const std::string &name, const int id, const std::string &password, const int age,
    const double balance) : User(name,id,password,age,balance){}

User * GoldUser::clone() const {
    return new GoldUser(*this);
}

double GoldUser::getDiscount() const {
    return discount;
}
