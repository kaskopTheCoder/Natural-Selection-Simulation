//
// Created by kacper on 11/10/26.
//

#include <app/Simulation.hpp>

namespace app {
    Simulation::Simulation() : world_(config_), evolution_(world_) {};

    void Simulation::runSimulation() {
        if (is_paused_) return;
        if (world_.getCreatures().empty()) {
            return;
        }

        if (world_.dayOver()) {
            evolution_.endDay(config_);

            world_.startDay();
            generation_++;

        }else {
            for (int i = 0; i < updates_per_frame_; i++) {
                world_.update(dt_);
            }
            food_left_ = 0;
            for (core::Food& f : world_.getFoods()) {
                if (f.eaten_) continue;
                food_left_ ++;
            }


        }

    }

    void Simulation::pause() {
        this->is_paused_ = !is_paused_;
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

    int Simulation::getGeneration() {
        return generation_;
    }

    int Simulation::getFoodLeft() {
        return food_left_;
    }

    void Simulation::speedUp() {
        if (updates_per_frame_ < 5) {
            updates_per_frame_++;
        }
    }

    void Simulation::slowDown() {
        if (updates_per_frame_ > 1) {
            updates_per_frame_--;
        }
    }

    int Simulation::getSpeed() {
        return updates_per_frame_;
    }

    bool Simulation::isPaused() {
        return is_paused_;
    }

    float Simulation::getFastestSpeed() {
        float best_speed =  0;
        for (core::Creature& c : world_.getCreatures()) {
            float loc_speed = c.getGenome().speed;

            if ( loc_speed > best_speed && !c.isExhausted()) best_speed = loc_speed;
        }

        return best_speed;
    }


}

