//
// Created by kacper on 5.11.2026.
//

#include <core/World.hpp>
#include <core/Config.hpp>
#include <numeric>
#include <algorithm>

namespace core {
    World::World(Config& cfg) : cfg_(cfg) {
        for (int i = 0; i < cfg_.number_of_creatures_; i++) {
            Creature c;
            c.setSpeed(cfg_.base_speed_);
            creatures_.push_back(c);
        }
    }

    void World::startDay() {
        setCreaturesOnEdges();
        placeFood();
        day_time_ = 0.f;
    }

    void World::setCreaturesOnEdges() {
        std::uniform_int_distribution<int> side(0,3);
        std::uniform_real_distribution<float> range(0.f, 1.f);
        const float world_width = cfg_.world_width_, world_height = cfg_.world_height_;
        for (Creature& c : creatures_) {
            float f = range(rnd_);
            switch (side(rnd_)) {
                case 0: c.setPosition({f * world_width, 0.f}); break;
                case 1: c.setPosition({f * world_width, world_height}); break;
                case 2: c.setPosition({world_width, f * world_height}); break;
                default: c.setPosition({0.f, f * world_height}); break;
            }
        }
    }

    void World::placeFood() {
        std::uniform_real_distribution<float> dx(0.f, 1.f);
        std::uniform_real_distribution<float> dy(0.f, 1.f);
        float H = cfg_.world_height_, W = cfg_.world_width_;
        for (int i = 0; i < cfg_.number_of_food_; i++) {
            float x = W * dx(rnd_);
            float y = H * dy(rnd_);
            foods_.push_back(Food{{x, y}, false});
        }
    }

    Food* World::searchNearestFood(Vec2 creature_pos) {
        Food* best = nullptr;
        float best_distance = 0.f;
        for (Food& food : foods_) {
            if (food.eaten_) continue;
            float d = distance(creature_pos, food.position_);
            if (!best || d < best_distance) { best_distance = d; best = &food; }
        }
        return best;

    }

    bool World::tryEat(Creature& creature, Food& food) {
        if (food.eaten_) { return false;}
        if (distance(creature.getPosition(), food.position_) > cfg_.eat_radius_) {return false;}
        food.eaten_ = true;
        creature.eat();
        return true;

    }

    void World::update(float dt) {
        day_time_ = day_time_ + dt;

        std::vector<int> order(creatures_.size());
        std::iota(order.begin(), order.end(), 0);
        std::shuffle(order.begin(), order.end(), rnd_);

        for (std::size_t i : order) {
            Creature& creature = creatures_[i];
            Food* target = searchNearestFood(creature.getPosition());
            if (!target) break;
            creature.moveToward(target->position_, dt);
            tryEat(creature, *target);
        }


    }

    int World::uneatenFood() {
        return static_cast<int>(std::count_if(foods_.begin(), foods_.end(), [](const Food& food) {return !food.eaten_;}));
    }

    bool World::dayOver() {
        return day_time_ >= cfg_.day_length_ || uneatenFood() == 0;
    }

    std::vector<Food>& World::getFoods() {
        return foods_;
    }

    std::vector<Creature>& World::getCreatures() {
        return creatures_;
    }

    void World::clearFoods() {
        foods_.clear();
    }
}
