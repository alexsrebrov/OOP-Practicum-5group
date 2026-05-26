#pragma once
#include<string>
#include<vector>
#include "Product.h"
class User {
protected:
    std::string name;
    int id;
    std::string password;
    int age;
    double balance;
    std::vector<Product*> basket;
public:
    User(const std::string& name,const int id,const std::string password,const int age,const double balance);
    virtual void seeBasket() const;
    virtual User* clone() const =0;
    virtual ~User();
    int getId() const;
    double getBalance() const;
    void addBalance(const double amount);
    bool deductBalance(const double amount);
    void addToBasket(const Product* p);
    void clearBasket();
    virtual double getDiscount() const = 0;
    std::vector<Product*> getBasket() const;
};


