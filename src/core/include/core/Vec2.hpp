//
// Created by kacper on 5.11.2026.
//

#ifndef MUTATIONSIM_VECTOR2_HPP
#define MUTATIONSIM_VECTOR2_HPP
#include <cmath>
#include <math.h>

namespace core {
    struct Vec2 {
        float x = 0.f, y = 0.f;

        Vec2 operator+(Vec2 o) {
            return {x + o.x, y + o.y};
        }
        Vec2 operator-(Vec2 o) {
            return {x - o.x, y - o.y};
        }
        Vec2 operator*(float f) {
            return {x * f, y * f};
        }

        float length() const {  return sqrt(x * x + y * y); }

        Vec2 normalized() const {
            float l = length();
            return l > 1e-6f ? Vec2{x / l, y / l} : Vec2{0.f, 0.f};

        }

    };
    inline float distance(Vec2 a, Vec2 b) { return (a-b).length(); }

}
#endif // MUTATIONSIM_VECTOR2_HPP
