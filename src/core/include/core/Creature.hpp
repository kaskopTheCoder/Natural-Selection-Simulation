//
// Created by kacper on 5.11.2026.
//
#ifndef MUTATIONSIM_CREATURE_HPP
#define MUTATIONSIM_CREATURE_HPP
#include <core/Vec2.hpp>

namespace core {
    class Creature {
    public:

        Creature();

        void moveToward(Vec2 destination, float dt);
        void eat();
        void setSpeed(float speed);
        void setPosition(Vec2 position);
        Vec2 getPosition();
        int getFoodEaten();
        void clearFoodEaten();
        float getSpeed();

    private:
        float speed_ = 0.f;
        int food_eaten_ = 0;
        Vec2 current_position_;



    };
}
#endif //MUTATIONSIM_CREATURE_HPP
