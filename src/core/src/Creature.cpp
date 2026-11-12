//
// Created by kacper on 5.11.2026.
//

#include <core/Creature.hpp>
#include <core/Genome.hpp>

namespace core {

    Creature::Creature(const Genome& genome, float starting_energy) : genome_(genome), energy_(starting_energy) {

    }

    void Creature::moveToward(Vec2 destination, float energy_cost, float dt) {
        Vec2 diff = destination - this->current_position_;
        float step = this->genome_.speed * dt;
        if (diff.length() < step) {
            this->current_position_ = destination;
        } else {
            this->current_position_ = this->current_position_ + diff.normalized() * step;
        }
        energy_ -= energy_cost * genome_.speed * genome_.speed * dt;


    }

    void Creature::eat(float food_energy) {
        food_eaten_++;
        energy_ += food_energy;
    }

    void Creature::setSpeed(float speed) {
        this->genome_.speed = speed;
    }

    void Creature::setPosition(Vec2 position) {
        this->current_position_ = position;
    }

    Vec2 Creature::getPosition() {
        return this->current_position_;
    }

    int Creature::getFoodEaten() {
        return food_eaten_;
    }

    void Creature::clearFoodEaten() {
        this->food_eaten_ = 0;
    }

    float Creature::getSpeed() {
        return this->genome_.speed;
    }

    const Genome& Creature::getGenome(){
        return this->genome_;
    }

    void Creature::setEnergy(float energy) {
        this->energy_ = energy;
    }

    float Creature::getEnergy() {
        return this->energy_;
    }

    bool Creature::isExhausted() {
        return (energy_ <= 0);
    }
    void Creature::addEnergy(float energy) {
        this->energy_ += energy;
    }
}
