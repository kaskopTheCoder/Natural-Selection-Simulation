//
// Created by kacper on 5.11.2026.
//

#ifndef MUTATIONSIM_EVOLUTION_HPP
#define MUTATIONSIM_EVOLUTION_HPP
#include <core/World.hpp>

namespace core {
    struct Evolution {
        World& world_;

        explicit Evolution(World& world);

        void endDay();
    };
}
#endif //MUTATIONSIM_EVOLUTION_HPP
