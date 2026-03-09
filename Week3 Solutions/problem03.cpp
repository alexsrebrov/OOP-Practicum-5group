#include<iostream>

const int MAX_NAME_SIZE=101;
const int MAX_RESTAURANTS=100;

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

    Restaurant() {
        strcpy(name,"no name");
        category=Category::FRENCH;
        isOpen=true;
        avrgPrice=0;
        rating=0;
    }

    const char* getName() const {
        return name;
    }

    double getRating() const {
        return rating;
    }

    bool getStatus() const {
        return isOpen;
    }

    Category getCat() const {
        return category;
    }

    double getAvrgPrice() const {
        return avrgPrice;
    }

    void setName(const char* name) {
        strcpy(this->name,name);
    }

    void setCat(Category cat) {
        category=cat;
    }

    void setAvrgPrice(double avrgPrice) {
        this->avrgPrice=avrgPrice;
    }

    Restaurant( char* name,Category cat,double avrgPrice): category(cat),avrgPrice(avrgPrice) {
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

class RestaurantChain {
    int count;
    Restaurant restaurants[MAX_RESTAURANTS];

public:

    int getCount() {
        return count;
    }

    RestaurantChain(Restaurant* restaurants,int count) : count(count) {
       if(count>MAX_RESTAURANTS){
       this->count=MAX_RESTAURANTS;
    }
       for (int i=0; i<this->count; ++i) {
           this->restaurants[i]=restaurants[i];
       }
    }

    RestaurantChain(Restaurant* restaurants,int count,Category cat) : count(count) {
       if(count>MAX_RESTAURANTS){
       this->count=MAX_RESTAURANTS;
    }
       int index=0;
       for (int i=0; i<this->count; ++i) {
           if (restaurants[i].getCat()==cat) {
               this->restaurants[index++]=restaurants[i];
           }
       }
       this->count=index;
    }

    void addRestaurant(Restaurant& rest) {
        if(count>=MAX_RESTAURANTS){
        return;
    }
        count++;
        restaurants[count-1]=rest;
    }

    void removeRestaurant(const char* name) {
        for (int i=0; i<count; ++i) {
            if (strcmp(restaurants[i].getName(),name)==0) {
               for (int j=i; j<count-1; ++j) {
                   std::swap(restaurants[j],restaurants[j+1]);
               }
               count--;
            }
        }
    }

    void sortByPrice() {
        for (int i=0; i<count; ++i) {
            for (int j=0; j<count-i-1; ++j) {
                if (restaurants[j].getAvrgPrice()>restaurants[j+1].getAvrgPrice()) {
                    std::swap(restaurants[j],restaurants[j+1]);
                }
            }
        }
    }

    void getMostExpensive(RestaurantChain& restChain,int num) {
        restChain.sortByPrice();
        int index=restChain.count-1;
        for (int i=0; i<num; ++i) {
            restChain.restaurants[index--].printRestaurantInfo();
        }
    }

    void printOpen() {
        for (int i=0; i<count; ++i) {
            if (restaurants[i].getStatus()==true)
            restaurants[i].printRestaurantInfo();
        }
    }

    void rateAll(double rating) {
        for (int i=0; i<count; ++i) {
            restaurants[i].rateRestaurant(rating);
            if (restaurants[i].getRating()<1) {
                restaurants[i].closeRestaurant();
            }
        }
    }

    double avrgPriceForCategory(Category cat) {
        double sum=0;
        int counter=0;
        for (int i=0; i<count; ++i) {
            if (restaurants[i].getCat()==cat) {
                sum+=restaurants[i].getAvrgPrice();
                counter++;
            }
        }
        return sum/counter;
    }
};
int main() {

}