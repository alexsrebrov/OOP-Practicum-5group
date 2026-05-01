#include "Player.h"

int Player::getID() const {
    return this -> id;
}

std::string Player::getName() const {
    return this -> name;
}

double Player::getMoney() const {
    return this -> money;
}

int Player::getNonchalantSkill() const {
    return this -> nonchalantSkill;
}

int Player::getLuck() const {
    return this -> luck;
}

int Player::getAura() const {
    return this -> aura;
}

void Player::addMoney(double money) {
    this -> money += money;
}

void Player::subtractMoney(double money) {
    this -> money -= money;
}
