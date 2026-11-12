#include <random>
//
// Created by kacper on 5.11.2026.
//

#include <core/Genome.hpp>
#include <algorithm>
namespace core {
    namespace {
        float mutateGene(float val, float min, float max, float strength, std::mt19937& gen) {
            std::normal_distribution<float> noise(0.f, strength * (max - min));
            return std::clamp(val + noise(gen), min, max);
        }
    }

    Genome randomGenome(const Config& config, std::mt19937& gen) {
        std::uniform_real_distribution<float> distribution(config.minimum_speed, config.maximum_speed);
        return Genome{distribution(gen)};
    }

    Genome mutate(const Genome& parentGenome, const Config& config, std::mt19937& gen) {
        Genome childGenome = parentGenome;
        std::uniform_real_distribution<float> distribution(0.f, 1.f);
        if (distribution(gen) < config.mutation_chance) {
            childGenome.speed = mutateGene(childGenome.speed, config.minimum_speed, config.maximum_speed,
                config.mutation_sterngth, gen);
        }
        return childGenome;

    }
}