#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Player.hpp"
#include "Enemy.hpp"

class GameManager {
public:
    GameManager();
    void startGame();

private:
    void  runBattle(Player& player, Enemy& enemy);
    Enemy makeEnemy(int level) const;
    void  printSeparator() const;

    int currentLevel;
    static const int TOTAL_LEVELS = 3;
};

#endif
