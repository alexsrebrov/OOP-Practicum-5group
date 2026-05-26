#pragma once
#include<string>

enum class Theme {
    STAR_WARS,
    NINJAGO,
    CITY
};

class LegoSet {
    std::string name;
    int id;
    static int counter;
    int pieceCount;
    Theme theme;
public:
    LegoSet() = delete;
    LegoSet(const std::string& name,const int pieceCount,const Theme theme);
    friend std::strong_ordering operator<=>(const LegoSet& lhs,const LegoSet& rhs);
    friend bool operator==(const LegoSet& lhs, const LegoSet& rhs);
    friend std::ostream& operator<<(std::ostream& os,const LegoSet& set);
    Theme getTheme() const;
    int getPieces() const;
};