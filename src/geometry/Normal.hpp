// Header file for normal class

#ifndef NORMAL_HPP
#define NORMAL_HPP

#include "Vector3.hpp"

namespace RT {

    // Normal needs its own class; it is like a vector but it supports
    // different operations and doesn't interact simply with transformations
    // (in general, a transformed surface normal is not normal to the
    // transformed surface.)
    class Normal {
    public:
        float x;
        float y;
        float z;

        Normal();
        Normal(float x_init, float y_init, float z_init);

        Normal operator+(const Normal& other) const;
        Normal& operator+=(const Normal& other);
        Normal operator-(const Normal& other) const;
        Normal& operator-=(const Normal& other);

        Normal operator*(const float scalar) const;
        Normal& operator*=(const float scalar);
        Normal operator/(const float scalar) const;
        Normal& operator/=(const float scalar);

        float length_squared() const;
        float length() const;
    };

    Normal abs(const Normal& n);
    Normal normalize(const Normal& n);
    float dot (const Normal& n, const Vector3& v);
    Normal operator*(float a, const Normal& n);
}

#endif