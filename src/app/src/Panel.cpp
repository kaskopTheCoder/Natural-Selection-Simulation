//
// Created by kacper on 11/21/26.
//

#include <app/Panel.hpp>


namespace app {

    Panel::Panel(app::Simulation& simulation, app::Controller& controller) : simulation_(simulation), controller_(controller) {}

    void Panel::startUserPanel() {
        ImGui::Begin("Symulacja");
        ImGui::Text("Food left: %d", simulation_.getFoodLeft());
        ImGui::Text("Generation: %d ", simulation_.getGeneration() );
        ImGui::Text(simulation_.isPaused() ? "Paused" : "Running");
        ImGui::Text("Spped of simulation: %d ", simulation_.getSpeed() );
        ImGui::Text("Maximum speed: %f", simulation_.getFastestSpeed());

        if (ImGui::Button("PAUSE")) {
            controller_.pauseSimulation();
        }
        if (ImGui::Button("SPEED UP")) {
            controller_.speedUpSimulation();
        }
        if (ImGui::Button("SLOW DOWN")) {
            controller_.slowDownSimulation();
        }
        ImGui::End();
    }
}
