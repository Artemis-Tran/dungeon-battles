#include "Player.hpp"
#include <algorithm>
#include <iostream>
#include <random>

static int rollDice(int min, int max) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

Player::Player(const std::string& name, int hp, int attack, int defense, int healCharges)
    : name(name), hp(hp), maxHp(hp), attack(attack), defense(defense),
      healCharges(healCharges), defending(false) {}

void Player::takeDamage(int damage) {
    int reduced = defending
        ? std::max(0, damage / 2 - defense)
        : std::max(0, damage - defense);
    hp = std::max(0, hp - reduced);
    std::cout << name << " takes " << reduced << " damage";
    if (defending) std::cout << " (defended!)";
    std::cout << "  [HP: " << hp << "/" << maxHp << "]\n";
}

int Player::rollAttack() const {
    return rollDice(attack - 3, attack + 5);
}

bool Player::isAlive() const {
    return hp > 0;
}

void Player::useHeal() {
    if (healCharges <= 0) {
        std::cout << "No heal charges left!\n";
        return;
    }
    int healed = std::min(maxHp - hp, 30);
    hp += healed;
    --healCharges;
    std::cout << name << " heals for " << healed << " HP!  [HP: " << hp << "/" << maxHp << "]\n";
}

void Player::setDefending(bool d) {
    defending = d;
}

void Player::display() const {
    std::cout << "[ " << name
              << " | HP: " << hp << "/" << maxHp
              << " | ATK: " << attack
              << " | DEF: " << defense
              << " | Heals: " << healCharges << " ]\n";
}

const std::string& Player::getName()      const { return name; }
int                Player::getHp()        const { return hp; }
int                Player::getMaxHp()     const { return maxHp; }
int                Player::getHealCharges() const { return healCharges; }
