#include "User.h"
#include<iostream>
User::User(const std::string &name, const int id, const std::string password, const int age, const double balance) : name(name),id(id),password(password),age(age),balance(balance){}

void User::seeBasket() const {
    std::cout<<"Basket:"<<std::endl;
    if (basket.empty()) {
        std::cout<<"Empty";
    }
    for (const Product* p : basket) {
        std::cout<<"Name:"<<p->getName()<<" Manufacturer:"<<p->getManufacturer()<<" Price:"<<p->getPrice()-p->getPrice()*getDiscount()<<"Size:"<<p->getSize();
        std::cout<<std::endl;
    }
}

User::~User() {
    clearBasket();
}

int User::getId() const {
    return id;
}

double User::getBalance() const {
    return balance;
}

void User::addBalance(const double amount) {
    balance+=amount;
}

bool User::deductBalance(const double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void User::addToBasket(const Product *p) {
    basket.push_back(p->clone());
}

void User::clearBasket() {
    for (Product* p : basket) {
        delete p;
    }
    basket.clear();
}

std::vector<Product *> User::getBasket() const {
    return basket;
}
