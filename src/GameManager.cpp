#include "GameManager.hpp"
#include <iostream>
#include <limits>

GameManager::GameManager() : currentLevel(1) {}

void GameManager::printSeparator() const {
    std::cout << "========================================\n";
}

Enemy GameManager::makeEnemy(int floor) const {
    switch (floor) {
        case 1: return Enemy("Goblin",       Stats{
                .hp = 100, .attack = 15, .defense = 5, .speed = 10,
                .critChance = 0.1f, .critDamage = 1.5f
            }, 1);
        case 2: return Enemy("Orc Warrior",  Stats{
                .hp = 120, .attack = 20, .defense = 10, .speed = 8,
                .critChance = 0.15f, .critDamage = 1.6f
            }, 2);
        case 3: return Enemy("Dark Dragon",  Stats{
                .hp = 150, .attack = 25, .defense = 15, .speed = 12,
                .critChance = 0.2f, .critDamage = 1.8f
            }, 3);
        default: return Enemy("Shadow",      Stats{
                .hp = 80, .attack = 10, .defense = 3, .speed = 6,
                .critChance = 0.05f, .critDamage = 1.3f
            }, 1);
    }
}

void GameManager::runBattle(Player& player, Enemy& enemy) {
    printSeparator();
    std::cout << "A wild " << enemy.getName() << " appears!\n";
    printSeparator();

    while (player.isAlive() && enemy.isAlive()) {
        std::cout << "\n";
        player.display();
        enemy.display();
        std::cout << "\nWhat do you do?\n"
                  << "  1) Attack\n"
                  << "  2) Defend  (halve incoming damage this turn)\n"
                  << "  3) Heal    (" << player.getHealCharges() << " charges, +30 HP each)\n"
                  << "> ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0;
        }

        player.setDefending(false);

        switch (choice) {
            case 1: {
                int dmg = player.rollAttack();
                std::cout << player.getName() << " attacks for " << dmg << " damage!\n";
                enemy.takeDamage(dmg);
                break;
            }
            case 2:
                player.setDefending(true);
                std::cout << player.getName() << " takes a defensive stance!\n";
                break;
            case 3:
                player.useHeal();
                break;
            default:
                std::cout << "You hesitate and lose your turn!\n";
                break;
        }

        if (!enemy.isAlive()) break;

        int enemyDmg = enemy.rollAttack();
        std::cout << enemy.getName() << " strikes for " << enemyDmg << "!\n";
        player.takeDamage(enemyDmg);
    }
}

void GameManager::startGame() {
    printSeparator();
    std::cout << "          DUNGEON BATTLES\n";
    printSeparator();

    std::string heroName;
    std::cout << "Enter your hero's name: ";
    std::cin >> heroName;

    int startingLevel = 1;
    int startingHealCharges = 3;

    Player player(heroName, Stats{
            .hp = 100, .attack = 20, .defense = 10, .speed = 10,
            .critChance = 0.1f, .critDamage = 1.5f
        }, startingLevel, startingHealCharges);
    std::cout << "\nWelcome, " << player.getName() << "! You descend into the dungeon...\n";

    for (currentLevel = 1; currentLevel <= TOTAL_LEVELS; ++currentLevel) {
        std::cout << "\n=== Level " << currentLevel << " ===\n";
        Enemy enemy = makeEnemy(currentLevel);
        runBattle(player, enemy);

        if (!player.isAlive()) {
            printSeparator();
            std::cout << "You have been slain. Game over!\n";
            printSeparator();
            return;
        }

        std::cout << "\n" << enemy.getName() << " has been defeated!\n";
        if (currentLevel < TOTAL_LEVELS)
            std::cout << "You press deeper into the dungeon...\n";
    }

    printSeparator();
    std::cout << "You cleared the dungeon! Congratulations, " << player.getName() << "!\n";
    printSeparator();
}
