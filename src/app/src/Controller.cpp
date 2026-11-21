//
// Created by kacper on 11/10/26.
//

#include <app/Controller.hpp>
#include <SFML/Graphics.hpp>

namespace app {

    Controller::Controller(app::Simulation& simulation) : simulation_(simulation){}

    void Controller::checkKeyBoardInput(sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up && updates_per_frame_ < 5) {
                updates_per_frame_++;
            }
            if (event.key.code == sf::Keyboard::Down && updates_per_frame_ > 1) {
                updates_per_frame_--;
            }
            if (event.key.code == sf::Keyboard::Space) {
                pauseSimulation();
            }
        }
    }

    void Controller::pauseSimulation() {
        simulation_.pause();
    }

    size_t Controller::getUpdatesPerFrame() {
        return updates_per_frame_;
    }

    bool Controller::isPaused() {
        return isPaused_;
    }
}
