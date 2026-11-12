//
// Created by kacper on 5.11.2026.
//

#include "core/Evolution.hpp"
#include <core/Creature.hpp>
#include <vector>

namespace core {
    Evolution::Evolution(World& world) : world_(world), gen_(world.getGenerator()) {

    };

    void Evolution::endDay(Config& cfg) {
        std::vector<Creature> nextGeneration;

        for (Creature& c : world_.getCreatures()) {
            if (c.isExhausted()) continue;
            Creature survivor = c;
            survivor.clearFoodEaten();
            nextGeneration.push_back(survivor);

            if (c.getEnergy() >= cfg.reproduction_threshold) {
                Genome parentGenome = survivor.getGenome();
                Creature child(mutate(parentGenome, cfg, gen_), cfg.starting_energy_);
                nextGeneration.push_back(child);
            }
        }



        world_.getCreatures() = std::move(nextGeneration);
    }
}
