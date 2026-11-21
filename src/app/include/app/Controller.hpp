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

        Controller(app::Simulation& simulation);

        void checkKeyBoardInput(sf::Event& event);
        void pauseSimulation();
        void speedUpSimulation();
        void slowDownSimulation();

        private:
        Simulation& simulation_;

    };
}



#endif //MUTATIONSIM_CONTROLLER_HPP
