//
// Created by kacper on 11/10/26.
//

#include <app/RenderHandler.hpp>
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
            window.draw(creature_shape_);
        }
    }
}
