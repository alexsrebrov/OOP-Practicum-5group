#ifndef LEGOSET_LEGOSET_H
#define LEGOSET_LEGOSET_H
#include <iostream>

class LegoSet {
protected:
    std::string name;
    size_t code;
    size_t pieceCount;
    std::string theme;
public:
    LegoSet();
    LegoSet(std::string name, int code, int pieceCount, std::string theme);
    std::strong_ordering operator<=>(const LegoSet &) const;
    bool operator==(const LegoSet &) const;
    friend std::ostream& operator<<(std::ostream &os, const LegoSet &set);
    std::string getName();
    size_t getCode();
    size_t getPieceCount();
    std::string getTheme();
};


#endif //LEGOSET_LEGOSET_H
