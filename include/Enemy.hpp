#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include "Character.hpp"

enum class Action { Attack, Defend, Heal };

class Enemy : public Character {
public:
    Enemy(const std::string& name, Stats stats, int level) : 
            Character(name, stats, level) {} ;

private:
    Action decideAction() const;  
    // Additional enemy-specific attributes can be added here

};

#endif
