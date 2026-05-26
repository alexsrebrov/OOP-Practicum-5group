
#include "BronzeUser.h"

BronzeUser::BronzeUser(const std::string &name, const int id, const std::string &password, const int age,
    const double balance) : User(name,id,password,age,balance){}

User * BronzeUser::clone() const {
    return new BronzeUser(*this);
}

double BronzeUser::getDiscount() const {
    return discount;
}
