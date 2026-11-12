//
// Created by kacper on 5.11.2026.
//
#ifndef MUTATIONSIM_CREATURE_HPP
#define MUTATIONSIM_CREATURE_HPP
#include <core/Vec2.hpp>
#include <core/Genome.hpp>

namespace core {
    class Creature {
    public:

        Creature(const Genome& genome, float starting_energy);

        void moveToward(Vec2 destination, float energy_cost,  float dt);
        void eat(float food_energy);
        void setSpeed(float speed);
        void setPosition(Vec2 position);
        Vec2 getPosition();
        int getFoodEaten();
        void clearFoodEaten();
        float getSpeed();
        const Genome& getGenome();
        void setEnergy(float energy);
        float getEnergy();
        bool isExhausted();
        void addEnergy(float energy);



    private:
        int food_eaten_ = 0;
        float energy_;
        Vec2 current_position_;
        Genome genome_;



    };
}
#endif //MUTATIONSIM_CREATURE_HPP
