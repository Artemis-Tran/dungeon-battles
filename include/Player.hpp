#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
public:
    Player(const std::string& name, int hp, int attack, int defense, int healCharges);

    void takeDamage(int damage);
    int  rollAttack() const;
    bool isAlive() const;
    void useHeal();
    void setDefending(bool defending);
    void display() const;

    const std::string& getName() const;
    int  getHp() const;
    int  getMaxHp() const;
    int  getHealCharges() const;

private:
    std::string name;
    int hp;
    int maxHp;
    int attack;
    int defense;
    int healCharges;
    bool defending;
};

#endif
