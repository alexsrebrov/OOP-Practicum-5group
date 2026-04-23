#pragma once
#include<iostream>
enum class Rarity {
    STANDART,
    SILVER,
    GOLD,
    PLATINUM
};

class Sticker {
    int id;
    char* name;
    unsigned rating;
    Rarity rarity;

    void copyFrom(const Sticker& other);
    void moveFrom(Sticker&&);
    void free();
public:
    Sticker();
    Sticker(const int id,const char* name,const unsigned rating,const Rarity rarity);
    Sticker(const Sticker& other);
    Sticker& operator=(const Sticker& other);
    Sticker(Sticker&& other) noexcept;
    Sticker& operator=(Sticker&& other) noexcept;
    ~Sticker();
    bool operator==(const Sticker& other) const;
    bool operator>(const Sticker& other) const;
    friend std::ostream& operator<<(std::ostream& os,const Sticker& sticker);
    unsigned getRating() const;
};
    std::ostream& operator<<(std::ostream& os,const Sticker& sticker);

inline std::ostream & operator<<(std::ostream &os, const Sticker &sticker) {
    os<<sticker.name<<" Rating:"<<sticker.rating<<" Rarity:";
    switch (sticker.rarity) {
        case Rarity::STANDART : os<<"Standart"; break;
        case Rarity::SILVER : os<<"Silver"; break;
        case Rarity::GOLD : os<<"Gold"; break;
        case Rarity::PLATINUM : os<<"Platinum"; break;
    }
    os<<std::endl;
    return os;
}

