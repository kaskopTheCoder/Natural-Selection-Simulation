//
// Created by kacper on 11/10/26.
//

#include <app/Application.hpp>
#include <SFML/Graphics.hpp>
#include <app/Simulation.hpp>
#include <app/RenderHandler.hpp>
#include "app/Controller.hpp"
#include <app/Panel.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

namespace app {

    void Application::startApplication() {
        app::Simulation simulation{};
        app::RenderHandler renderHandler;
        app::Controller controller(simulation);
        app::Panel panel(simulation, controller);

        sf::RenderWindow window(sf::VideoMode(1600, 1200 ), "Simulation");
        window.setFramerateLimit(60);

        if (!ImGui::SFML::Init(window)) return;
        ImGui::GetIO().FontGlobalScale = 2.5f;
        sf::Clock deltaClock;


        renderHandler.setUpShapes();

        simulation.getWorld().startDay();



        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                ImGui::SFML::ProcessEvent(window, event);
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                controller.checkKeyBoardInput(event);
            }

            ImGui::SFML::Update(window, deltaClock.restart());

            window.clear(sf::Color(18,20,26));

            panel.startUserPanel();

            simulation.runSimulation();
            window.clear(sf::Color(18,20,26));
            renderHandler.renderFood(window, simulation.getWorld());
            renderHandler.renderCreatures(window, simulation.getWorld());



            ImGui::SFML::Render(window);

            window.display();
        }

        ImGui::SFML::Shutdown();
    }
}
