//
// Created by kacper on 5.11.2026.
//

#ifndef MUTATIONSIM_CONFIG_HPP
#define MUTATIONSIM_CONFIG_HPP
namespace core {
    struct Config {
        float world_width_ = 800.f;
        float world_height_ = 600.f;
        float day_length_ = 30.f;
        int number_of_days_ = 10;
        int number_of_creatures_ = 40;
        int number_of_food_ = 30;
        float base_speed_ = 20.f;
        float minimum_speed = 40.f;
        float maximum_speed = 160.f;
        float reproduction_threshold = 90.f;
        float mutation_sterngth = 0.07f;
        float mutation_chance = .3f;
        float eat_radius_ = 3.f;
        float starting_energy_ = 50.f;
        float food_energy = 40.f;
        float speed_cost = 0.0004f;
    };
}
#endif //MUTATIONSIM_CONFIG_HPP
