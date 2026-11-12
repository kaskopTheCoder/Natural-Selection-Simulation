//
// Created by kacper on 11/10/26.
//

#ifndef MUTATIONSIM_RENDERHANDLER_HPP
#define MUTATIONSIM_RENDERHANDLER_HPP

#include <SFML/Graphics.hpp>
#include <core/Config.hpp>
#include <core/World.hpp>

namespace app {
    class RenderHandler {
    public:
        void setUpShapes();
        sf::Color getCreatureColor(float speed);
        void renderCreatures(sf::RenderWindow& window, core::World& world);
        void renderFood(sf::RenderWindow& window, core::World& world);

    private:
        core::Config config_;
        sf::CircleShape food_shape_;
        sf::CircleShape creature_shape_;
    };
}



#endif //MUTATIONSIM_RENDERHANDLER_HPP
