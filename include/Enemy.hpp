#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int hp, int attack);

    void takeDamage(int damage);
    int  rollAttack() const;
    bool isAlive() const;
    void display() const;

    const std::string& getName() const;
    int getHp() const;

private:
    std::string name;
    int hp;
    int attack;
};

#endif
