//
// Created by kacper on 5.11.2026.
//

#ifndef MUTATIONSIM_WORLD_HPP
#define MUTATIONSIM_WORLD_HPP
#include <vector>
#include <core/Config.hpp>
#include <core/Creature.hpp>
#include <core/Food.hpp>
#include <random>
namespace core {
    class World {
    public:
        World(Config& cfg);

        void startDay();
        void placeFood();
        void setCreaturesOnEdges();
        Food* searchNearestFood(Vec2 creature_pos);
        bool dayOver();
        bool tryEat(Creature& creature, Food& food);
        int uneatenFood();
        void update(float dt);
        std::vector<Creature>& getCreatures();
        std::vector<Food>& getFoods();
        void clearFoods();
        std::mt19937& getGenerator();

    private:
        Config& cfg_;
        std::mt19937 rnd_;


        std::vector<Creature> creatures_;
        std::vector<Food> foods_;

        float day_time_ = 0.f;



    };
}
#endif //MUTATIONSIM_WORLD_HPP
