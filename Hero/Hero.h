#ifndef HERO_HERO_H
#define HERO_HERO_H

enum class Type {
    Tank, Support, Assassin, Controller, Marksman
};
enum class Result {
    Win, Loss, Draw
};
class Hero {
    Type type;
    char* name;
    int hp;
    int damagePerShot;
    int attackDelay;
    Result* result;
    int size;
    int capacity;
    void free();
    void copyFrom(const Hero&);
    void moveFrom(Hero&&);
    void resize();
    void resize(Hero&);
public:
    Hero();
    Hero(const Hero&);
    Hero(Hero&&);
    Hero& operator=(const Hero&);
    Hero& operator=(Hero&&);
    ~Hero();
    void fight(Hero&);
    void heroInfo();
    void gameHistory();
    auto operator<=>(const Hero&) const;
};



#endif //HERO_HERO_H
