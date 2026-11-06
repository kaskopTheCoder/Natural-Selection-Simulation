//
// Created by kacper on 5.11.2026.
//

#include <core/Creature.hpp>

namespace core {

    void Creature::moveToward(Vec2 destination, float dt) {
        Vec2 diff = destination - this->current_position_;
        float step = this->speed_ * dt;
        if (diff.length() < step) {
            this->current_position_ = destination;

            return;
        }
        this->current_position_ = this->current_position_ + diff.normalized() * step;

    }

    void Creature::eat() {
        food_eaten_++;
    }

    void Creature::setSpeed(float speed) {
        this->speed_ = speed;
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
}
