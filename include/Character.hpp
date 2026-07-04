#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

struct Stats {
    int hp;
    int attack;
    int defense;
    int speed;
    
    float critChance;
    float critDamage;

};
 
class Character {
    public: 
        Character(const std::string& name, Stats stats, int level);

        virtual void takeDamage(int damage);
        virtual void display() const;

        int  rollAttack() const;
        bool isAlive() const;

        const std::string& getName() const;
        const Stats& getStats() const;
        int getCurrentHp() const;
        void heal(int amount);
    private:
        std::string name;
        Stats stats;   
        int level;
        int currentHp;
};

#endif 