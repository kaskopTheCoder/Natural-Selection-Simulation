//
// Created by kacper on 5.11.2026.
//
#include <cstdio>
#include <core/World.hpp>
#include <core/Evolution.hpp>

int main() {
    core::Config config;
    core::World world(config);
    core::Evolution evolution(world);

    float dt = 1.f/60.f;

    for (int g = 0; g < config.number_of_days_; g++) {
        printf("Generation number %d\n", g + 1);
        world.startDay();

        while (!world.dayOver()) {
            world.update(dt);
        }
        int i = 0;
        for (core::Creature& c : world.getCreatures()) {
            printf("Creature %d ate %d food\n", i++, c.getFoodEaten());
        }

        evolution.endDay(config);

    }
}