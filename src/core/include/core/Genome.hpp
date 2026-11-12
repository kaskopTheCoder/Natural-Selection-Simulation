//
// Created by kacper on 5.11.2026.
//

#ifndef MUTATIONSIM_GNOME_HPP
#define MUTATIONSIM_GNOME_HPP
#include <core/Config.hpp>
#include <random>

namespace core {
    struct Genome {
        float speed = 80.f;
    };

    Genome randomGenome(const Config& config, std::mt19937& gen);
    Genome mutate(const Genome& parentGenome, const Config& config, std::mt19937& gen);
}
#endif //MUTATIONSIM_GNOME_HPP
