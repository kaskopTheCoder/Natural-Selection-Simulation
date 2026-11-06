//
// Created by kacper on 5.11.2026.
//

#ifndef MUTATIONSIM_FOOD_HPP
#define MUTATIONSIM_FOOD_HPP

#include <core/Vec2.hpp>
namespace core {
    struct Food {
        Vec2 position_;
        bool eaten_ = false;

    };
}
#endif //MUTATIONSIM_FOOD_HPP
