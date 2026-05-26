#pragma once
#include "User.h"
class GoldUser : public User {
    double discount=0.2;
public:
    GoldUser(const std::string& name,const int id,const std::string& password,const int age,const double balance);
    User* clone() const override;
    double getDiscount() const override;
};