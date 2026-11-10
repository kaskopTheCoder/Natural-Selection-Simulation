//
// Created by kacper on 11/10/26.
//

#ifndef MUTATIONSIM_SIMULATION_HPP
#define MUTATIONSIM_SIMULATION_HPP

#include <core/World.hpp>
#include <core/Config.hpp>
#include <core/Evolution.hpp>

namespace app {
    class Simulation {
    public:
        Simulation();

        void runSimulation(size_t updates_per_frame);
        core::World& getWorld();
        float getWorldHeight();
        float getWorldWidth();

    private:
        core::Config config_;
        core::World world_;
        core::Evolution evolution_;
        float dt_ = 1.f/60.f;

    };
}


#endif //MUTATIONSIM_SIMULATION_HPP
