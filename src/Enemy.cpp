#include "Enemy.hpp"
#include "Combat.hpp"
#include <algorithm>
#include <iostream>
#include <random>


Action Enemy::decideAction() const {
    int roll = combat::rollDice(1, 100);
    if (roll <= 60) {
        return Action::Attack;
    } else if (roll <= 85) {
        return Action::Defend;
    } else {
        return Action::Heal;
    }
}


