#include "Character.hpp"
#include <algorithm>
#include <iostream>
#include <random>

static int rollDice(int min, int max) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

Character::Character(const std::string& name, Stats stats, int level)
    : name(name), stats(stats), level(level), currentHp(stats.hp) {}

void Character::takeDamage(int damage) {
    int realDamage = std::max(0, damage - stats.defense);
    currentHp = std::max(0, currentHp - realDamage);
    std::cout << name << " takes " << realDamage << " damage!  [HP: " << currentHp << "]\n";
}

int Character::rollAttack() const {
    return rollDice(stats.attack - 2, stats.attack + 4);
}

bool Character::isAlive() const {
    return currentHp > 0;
}

void Character::display() const {
    std::cout << "[ " << name << " | HP: " << currentHp << " | ATK: " << stats.attack << " ]\n";
}

void Character::heal(int amount) {
    currentHp = std::min(currentHp + amount, stats.hp);
}

const std::string& Character::getName() const { return name; }
const Stats&      Character::getStats()   const { return stats; }
int Character::getCurrentHp() const { return currentHp; }

