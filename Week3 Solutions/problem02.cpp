#include<iostream>

const int MAX_NAME_SIZE=101;

enum class Category {
    ITALIAN,
    CHINESE,
    AMERICAN,
    FRENCH,
    JAPANESE
};

class Restaurant {

    char name[MAX_NAME_SIZE];
    Category category;
    bool isOpen=true;
    double avrgPrice;
    double rating=0;
public:

    double getRating() const {
        return rating;
    }

    bool getStatus() const {
        return isOpen;
    }

    Restaurant(const char* name,Category cat,double avrgPrice): category(cat),avrgPrice(avrgPrice) {
        strcpy(this->name,name);
    }

    void openRestaurant() {
        isOpen=true;
    }

    void closeRestaurant() {
        isOpen=false;
    }

    void rateRestaurant(double newRating) {
        if (newRating<0 || newRating>5) {
            return;
        }
        rating=(rating+newRating)/2;
    }

    void CategoryToString(Category cat) const {
        switch (cat) {
            case Category::ITALIAN : std::cout<<"Italian"<<std::endl; break;
            case Category::CHINESE : std::cout<<"Chinese"<<std::endl; break;
            case Category::AMERICAN : std::cout<<"American"<<std::endl; break;
            case Category::FRENCH : std::cout<<"French"<<std::endl; break;
            case Category::JAPANESE : std::cout<<"Japanese"<<std::endl; break;
        }
    }

    void printRestaurantInfo() const {
        std::cout<<name<<std::endl;
        CategoryToString(category);
        if (isOpen) {
            std::cout<<"The restaurant is open!"<<std::endl;
        }
        else {
            std::cout<<"The restaurant is closed!"<<std::endl;
        }
        std::cout<<"Rating:"<<rating<<std::endl;
        std::cout<<"Avrg price:"<<avrgPrice<<std::endl;
    }
};
int main() {
    Restaurant rest("Halkidiki",Category::FRENCH,30);
    rest.printRestaurantInfo();
    rest.closeRestaurant();
    rest.printRestaurantInfo();
    rest.rateRestaurant(4);
    std::cout<<rest.getRating()<<std::endl;
    std::cout<<rest.getStatus();
}