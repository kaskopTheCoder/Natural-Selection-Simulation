//
// Created by kacper on 11/10/26.
//

#include <app/Application.hpp>
#include <SFML/Graphics.hpp>
#include <app/Simulation.hpp>
#include <app/RenderHandler.hpp>
#include "app/Controller.hpp"
#include <iostream>

namespace app {

    void Application::startApplication() {
        app::Simulation simulation{};
        app::RenderHandler renderHandler;
        app::Controller controller;

        sf::RenderWindow window(sf::VideoMode(1600, 1200 ), "Simulation");
        window.setFramerateLimit(60);

        renderHandler.setUpShapes();

        simulation.getWorld().startDay();



        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                controller.checkKeyBoardInput(event);
            }


            printf("Speed set to: %ld", controller.getUpdatesPerFrame());
            printf(controller.isPaused() ? "Paused\n" : "Running\n");

            window.clear(sf::Color(18,20,26));

            if (!controller.isPaused()) {
                simulation.runSimulation(controller.getUpdatesPerFrame());
                window.clear(sf::Color(18,20,26));
                renderHandler.renderFood(window, simulation.getWorld());
                renderHandler.renderCreatures(window, simulation.getWorld());
            }




            window.display();
        }
    }
}
