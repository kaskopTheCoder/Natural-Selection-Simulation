//
// Created by kacper on 11/10/26.
//

#include <app/Controller.hpp>
#include <SFML/Graphics.hpp>

namespace app {

    Controller::Controller(app::Simulation& simulation) : simulation_(simulation){}

    void Controller::checkKeyBoardInput(sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                speedUpSimulation();
            }
            if (event.key.code == sf::Keyboard::Down) {
                slowDownSimulation();
            }
            if (event.key.code == sf::Keyboard::Space) {
                pauseSimulation();
            }
        }
    }

    void Controller::pauseSimulation() {
        simulation_.pause();
    }

    void Controller::speedUpSimulation() {
        simulation_.speedUp();
    }

    void Controller::slowDownSimulation() {
        simulation_.slowDown();
    }
}
