#include "Player.hpp"
#include <algorithm>
#include <iostream>
#include <random>




void Player::takeDamage(int damage) {
    int reduced = defending
        ? std ::max(0, damage / 2)
        : std::max(0, damage);
    Character::takeDamage(reduced);

    if (defending) std::cout << " (defended!)";
}


void Player::useHeal() {
    if (healCharges <= 0) {
        std::cout << "No heal charges left!\n";
        return;
    }
    int healed = std::min(getStats().hp - getCurrentHp(), 30);
    Character::heal(healed);
    --healCharges;
    std::cout << getName() << " heals for " << healed << " HP!  [HP: " << getCurrentHp() << "/" << getStats().hp << "]\n";
}

void Player::setDefending(bool d) {
    defending = d;
}

void Player::display() const {
    std::cout << "[ " << getName()
              << " | HP: " << getCurrentHp() << "/" << getStats().hp
              << " | ATK: " << getStats().attack
              << " | DEF: " << getStats().defense
              << " | Heals: " << healCharges << " ]\n";
}

int Player::getHealCharges() const { return healCharges; }

