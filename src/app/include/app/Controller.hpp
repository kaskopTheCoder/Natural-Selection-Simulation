//
// Created by kacper on 11/10/26.
//

#ifndef MUTATIONSIM_CONTROLLER_HPP
#define MUTATIONSIM_CONTROLLER_HPP
#include "Simulation.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace app {
    class Controller {
        public:

        void checkKeyBoardInput(sf::Event& event);
        size_t getUpdatesPerFrame();
        bool isPaused();

        private:

        size_t updates_per_frame_ = 1;
        bool isPaused_ = true;

    };
}



#endif //MUTATIONSIM_CONTROLLER_HPP
