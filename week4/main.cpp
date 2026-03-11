#include <iostream>
#include <utility>
using namespace std;

class Product {
    string name;
    double price = 0;
public:
    Product() = default;
    Product(string name, const double price) : name(std::move(name)), price(price) {}
    string toString() const {
        return format("{}, {}", name, price);
    }
};
class Cart {
    Product* products;
    int size;
public:
    Cart() : products(nullptr), size(0) {}
    ~Cart() {
        delete[] products;
    }
    void add(const Product& product) {
        Product* newProducts = new Product[size + 1];
        for (int i = 0; i < size; i++) {
            newProducts[i] = products[i];
        }
        newProducts[size++] = product;
        delete[] products;
        products = newProducts;
    }
    void print() const {
        println("Items in cart:");
        for (int i = 0; i < size; i++) {
            println("{}", products[i].toString());
        }
    }
};
class Client {
    Cart* cart;
public:
    Client() : cart(nullptr) {}
    explicit Client(Cart* cart) : cart(cart) {}
};
int main() {
    const Product p1("Car", 6);
    const Product p2("TV", 500);
    const Product p3("Paper", 5);
    Cart c;
    c.add(p1);
    c.add(p2);
    c.add(p3);
    c.print();
}