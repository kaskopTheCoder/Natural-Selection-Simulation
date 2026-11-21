//
// Created by kacper on 11/21/26.
//

#ifndef MUTATIONSIM_PANEL_HPP
#define MUTATIONSIM_PANEL_HPP

#include <imgui.h>
#include <imgui-SFML.h>
#include <app/Simulation.hpp>
#include <app/Controller.hpp>

#include "Controller.hpp"

namespace app {
    class Panel {
    public:
        Panel(Simulation& simulation, Controller& controller);
        void startUserPanel();

    private:
        Simulation& simulation_;
        Controller& controller_;
    };
}

#endif //MUTATIONSIM_PANEL_HPP
