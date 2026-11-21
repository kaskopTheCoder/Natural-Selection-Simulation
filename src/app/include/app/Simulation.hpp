//
// Created by kacper on 11/10/26.
//

#ifndef MUTATIONSIM_SIMULATION_HPP
#define MUTATIONSIM_SIMULATION_HPP

#include <core/World.hpp>
#include <core/Config.hpp>
#include <core/Evolution.hpp>
#include <core/Creature.hpp>

namespace app {
    class Simulation {
    public:
        Simulation();

        void runSimulation();
        core::World& getWorld();
        float getWorldHeight();
        float getWorldWidth();
        void pause();
        int getGeneration();
        int getFoodLeft();
        void speedUp();
        void slowDown();
        int getSpeed();
        bool isPaused();
        float getFastestSpeed();

    private:
        core::Config config_;
        core::World world_;
        core::Evolution evolution_;

        bool is_paused_ = true;
        int updates_per_frame_ = 1;
        float dt_ = 1.f/60.f;


        int generation_ = 1;
        int food_left_ = 0;
        int creatures_alive_ = 0;

    };
}


#endif //MUTATIONSIM_SIMULATION_HPP
