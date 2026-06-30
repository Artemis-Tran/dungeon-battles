#include "Enemy.hpp"
#include <algorithm>
#include <iostream>
#include <random>

static int rollDice(int min, int max) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

Enemy::Enemy(const std::string& name, int hp, int attack)
    : name(name), hp(hp), attack(attack) {}

void Enemy::takeDamage(int damage) {
    hp = std::max(0, hp - damage);
    std::cout << name << " takes " << damage << " damage!  [HP: " << hp << "]\n";
}

int Enemy::rollAttack() const {
    return rollDice(attack - 2, attack + 4);
}

bool Enemy::isAlive() const {
    return hp > 0;
}

void Enemy::display() const {
    std::cout << "[ " << name << " | HP: " << hp << " | ATK: " << attack << " ]\n";
}

const std::string& Enemy::getName() const { return name; }
int                Enemy::getHp()   const { return hp; }
