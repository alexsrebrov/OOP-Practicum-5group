#ifndef GAMEHOUSE_PLAYER_H
#define GAMEHOUSE_PLAYER_H
#include <string>


class Player {
    int id;
    std::string name;
    double money;
    int nonchalantSkill;
    int luck;
    int aura;
public:
    Player() = delete;
    int getID() const;
    std::string getName() const;
    double getMoney() const;
    int getNonchalantSkill() const;
    int getLuck() const;
    int getAura() const;
    void addMoney(double money);
    void subtractMoney(double money);
};



#endif //GAMEHOUSE_PLAYER_H
