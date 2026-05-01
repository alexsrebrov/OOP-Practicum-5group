#include "Hero.h"
#pragma warning(disable:4996)
#include <iostream>
using namespace std;

void Hero::free() {
    delete[] name;
    delete[] result;
}

void Hero::copyFrom(const Hero& other) {
    this -> type = other.type;
    this -> name = new char[strlen(other.name) + 1];
    strcpy(this -> name, other.name);
    this -> hp = other.hp;
    this -> damagePerShot = other.damagePerShot;
    this -> attackDelay = other.attackDelay;
    this -> result = new Result[other.size];
    for (int i = 0; i < other.size; i++) {
        this -> result[i] = other.result[i];
    }
    this -> size = other.size;
    this -> capacity = other.capacity;
}

void Hero::moveFrom(Hero&& other) {
    this -> type = other.type;
    this -> name = other.name;
    other.name = nullptr;
    this -> hp = other.hp;
    this -> damagePerShot = other.damagePerShot;
    this -> attackDelay = other.attackDelay;
    this -> result = other.result;
    other.result = nullptr;
    this -> size = other.size;
    this -> capacity = other.capacity;
}

Hero::Hero() : type(Type::Tank), name(nullptr), hp(0), damagePerShot(0), attackDelay(0), result(nullptr), size(0), capacity(0) {}


Hero::Hero(const Hero& other) {
    copyFrom(other);
}

Hero::Hero(Hero&& other) {
    moveFrom(std::move(other));
}

Hero& Hero::operator=(const Hero& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Hero& Hero::operator=(Hero&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Hero::~Hero() {
    free();
}

void Hero::resize() {
    if (capacity == 0) {
        capacity = 1;
        this -> result = new Result[capacity];
    }
    else {
        auto temp = new Result[capacity * 2];
        for (int i = 0; i < size; i++) {
            temp[i] = result[i];
        }
        delete[] result;
        result = temp;
        capacity *= 2;
    }
}
void Hero::resize(Hero& other) {
    if (other.capacity == 0) {
        other.capacity = 1;
        other.result = new Result[other.capacity];
    }
    else {
        auto temp = new Result[other.capacity * 2];
        for (int i = 0; i < other.size; i++) {
            temp[i] = other.result[i];
        }
        delete[] other.result;
        other.result = temp;
        other.capacity *= 2;
    }
}

void Hero::fight(Hero& other) {
    int secondsToKillOther = 0, secondsToKillThis = 0;
    secondsToKillOther = other.hp * attackDelay / damagePerShot;
    secondsToKillThis = this -> hp * other.attackDelay / other.damagePerShot;
    if (this -> size == this -> capacity) {
        resize();
    }
    if (other.size == other.capacity) {
        resize(other);
    }
    if (secondsToKillOther > secondsToKillThis) {
        this -> result[size++] = Result::Loss;
        other.result[other.size++] = Result::Win;
    }
    else if (secondsToKillOther < secondsToKillThis) {
        this -> result[size++] = Result::Win;
        other.result[other.size++] = Result::Loss;
    }
    else {
        this -> result[size++] = Result::Draw;
        other.result[other.size++] = Result::Draw;
    }
}

void Hero::heroInfo() {
    println("Name: {}, hp: {}, dps: {}, at: {}", name, hp, damagePerShot, attackDelay);
}

void Hero::gameHistory() {
    for (int i = 0; i < size; i++) {
        if (this -> result[i] == Result::Win) {
            printf("Win ");
        }
        else if (this -> result[i] == Result::Loss) {
            printf("Loss ");
        }
        else {
            printf("Draw ");
        }
    }
    println();
}

auto Hero::operator<=>(const Hero& other) const {
    int secondsToKillOther = 0, secondsToKillThis = 0;
    secondsToKillOther = other.hp * attackDelay / damagePerShot;
    secondsToKillThis = this -> hp * other.attackDelay / other.damagePerShot;
    return secondsToKillOther <=> secondsToKillThis;
}