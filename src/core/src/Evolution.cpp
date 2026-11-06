//
// Created by kacper on 5.11.2026.
//

#include "core/Evolution.hpp"
#include <core/Creature.hpp>
#include <vector>

namespace core {
    Evolution::Evolution(World& world) : world_(world) {};

    void Evolution::endDay() {
        std::vector<Creature> nextGeneration;

        for (Creature& c : world_.getCreatures()) {
            if (c.getFoodEaten() == 0) continue;
            Creature survivor = c;
            survivor.clearFoodEaten();
            nextGeneration.push_back(survivor);

            if (c.getFoodEaten() >= 2) {
                nextGeneration.push_back(survivor);
            }
        }



        world_.getCreatures() = std::move(nextGeneration);
    }
}
