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
        int number_of_creatures_ =50;
        int number_of_food_ = 45;
        float base_speed_ = 20.f;
        float eat_radius_ = 3.f;
    };
}
#endif //MUTATIONSIM_CONFIG_HPP
