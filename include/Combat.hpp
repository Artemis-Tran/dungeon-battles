#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <random>

namespace combat {

    inline std::mt19937& rng() {
        static std::mt19937 engine(std::random_device{}());
        return engine;
    }

    inline int rollDice(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng());
    }

    inline bool rollChance(int percentChance) {
        std::uniform_int_distribution<int> dist(1, 100);
        return dist(rng()) <= percentChance;
    }

} // namespace combat

#endif
