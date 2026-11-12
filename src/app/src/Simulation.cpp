//
// Created by kacper on 11/10/26.
//

#include <app/Simulation.hpp>

namespace app {
    Simulation::Simulation() : world_(config_), evolution_(world_) {};

    void Simulation::runSimulation(size_t updates_per_frame) {
        if (is_paused_) return;
        if (world_.getCreatures().empty()) {
            return;
        }

        if (world_.dayOver()) {
            evolution_.endDay(config_);

            world_.startDay();
            generation_++;

        }else {
            for (int i = 0; i < updates_per_frame; i++) {
                world_.update(dt_);
            }
            food_left_ = 0;
            for (core::Food& f : world_.getFoods()) {
                if (f.eaten_) continue;
                food_left_ ++;
            }


        }

    }

    core::World& Simulation::getWorld() {
        return world_;
    }

    float Simulation::getWorldHeight() {
        return config_.world_height_;
    }

    float Simulation::getWorldWidth() {
        return config_.world_width_;
    }

    void Simulation::checkIfPaused(bool isPaused) {
        is_paused_ = isPaused;
    }

    int Simulation::getGeneration() {
        return generation_;
    }

    int Simulation::getFoodLeft() {
        return food_left_;
    }
}

