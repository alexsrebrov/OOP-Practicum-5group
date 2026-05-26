
#include<iostream>
#include "FoodMarket.h"

User * FoodMarket::findUser(const int id) const {
    for (User* u : users) {
        if (u->getId() == id) return u;
    }
    return nullptr;
}

Product * FoodMarket::findProduct(const int id) const {
    for (Product* p : products) {
        if (p->getId() == id) return p;
    }
    return nullptr;
}


FoodMarket::~FoodMarket() {
    for (Product* p : products) {
        delete p;
    }
    for (User* u : users) {
        delete u;
    }
}

void FoodMarket::addUser(const User &user) {
    users.push_back(user.clone());
}

void FoodMarket::addProduct(const Product &product) {
    products.push_back(product.clone());
}

void FoodMarket::addProductToBasket(const int userID, const int productID) {
    User* u = findUser(userID);
    Product* p =findProduct(productID);
    u->addToBasket(p);
}

void FoodMarket::likeProduct(const int id) {
    Product* p = findProduct(id);
    p->addLike();
}

void FoodMarket::manageUserBalance(const int id, const double amount) {
    User* u = findUser(id);
    u->addBalance(amount);
}

void FoodMarket::buyProducts(const int id) {
    User* u = findUser(id);
    double totalPrice=0;
    for (Product* p : u->getBasket()) {
       totalPrice+=p->getPrice();
    }
    double discount=u->getDiscount();
    totalPrice=totalPrice-totalPrice*discount;
    if (u->deductBalance(totalPrice)) {
        std::cout<<"Purchase successful!";
        u->clearBasket();
    }
    else {
        std::cout<<"Not enough balance!";
    }
}
