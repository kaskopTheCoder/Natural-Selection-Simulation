//
// Created by kacper on 11/10/26.
//

#include <app/RenderHandler.hpp>
#include <algorithm>
#include <iostream>

namespace app {

    void RenderHandler::setUpShapes() {
        food_shape_.setRadius(config_.eat_radius_);
        food_shape_.setFillColor(sf::Color(235, 64, 52));
        food_shape_.setOrigin(config_.eat_radius_ / 2.f, config_.eat_radius_ / 2.f);

        creature_shape_.setRadius(3.f);
        creature_shape_.setFillColor(sf::Color(138, 168, 143));
        creature_shape_.setOrigin(3.f, 3.f);
    }

    sf::Color RenderHandler::getCreatureColor(float speed) {
        float range = config_.maximum_speed - config_.minimum_speed;
        float t = (range > 0.f) ? (speed - config_.minimum_speed)/range : 0.5f;
        t = std::clamp(t, 0.f, 1.f);

        sf::Uint8 r = static_cast<sf::Uint8>(40 + t * 175);
        sf::Uint8 g = static_cast<sf::Uint8>(80 + t * 400);
        sf::Uint8 b = static_cast<sf::Uint8>(60 + t * 175);

        return sf::Color(r, g, b);



    }

    void RenderHandler::renderFood(sf::RenderWindow& window, core::World& world){
        for (core::Food& f : world.getFoods()) {
            if (f.eaten_) continue;
            core::Vec2 position = f.position_;
            food_shape_.setPosition(position.x, position.y);
            window.draw(food_shape_);
        }
    }

    void RenderHandler::renderCreatures(sf::RenderWindow& window, core::World& world){
        for (core::Creature& c : world.getCreatures()) {
            core::Vec2 position = c.getPosition();
            creature_shape_.setPosition(position.x, position.y);
            creature_shape_.setFillColor(getCreatureColor(c.getSpeed()));
            window.draw(creature_shape_);
        }
    }
}
