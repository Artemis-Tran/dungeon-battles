#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Character.hpp"

class Player : public Character {
public:
    Player(const std::string& name, Stats stats, int level, int healCharges)
        : Character(name, stats, level), healCharges(healCharges), defending(false) {};

    void useHeal();
    void setDefending(bool defending);
    void display() const override;
    void takeDamage(int damage) override;

    int  getHealCharges() const;

private:
    int healCharges;
    bool defending;
};

#endif
