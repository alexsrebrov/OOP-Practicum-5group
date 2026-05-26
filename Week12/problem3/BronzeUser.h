#pragma once
#include "User.h"
class BronzeUser : public User {
    double discount=0;
public:
    BronzeUser(const std::string& name,const int id,const std::string& password,const int age,const double balance);
    User* clone() const override;
    double getDiscount() const override;
};