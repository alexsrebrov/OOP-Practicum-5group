#pragma once
#include<vector>
#include "Product.h"
#include "User.h"
class FoodMarket {
    std::vector<Product*> products;
    std::vector<User*> users;
public:
    User* findUser(const int id) const ;
    Product* findProduct(const int id) const;
    FoodMarket() = default;
    ~FoodMarket();
    void addUser(const User& user);
    void addProduct(const Product& product);
    void addProductToBasket(const int userID,const int productID);
    void likeProduct(const int id);
    void manageUserBalance(const int id,const double amount);
    void buyProducts(const int id);
};