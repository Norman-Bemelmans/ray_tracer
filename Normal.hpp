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
        double x;
        double y;
        double z;

        Normal();
        Normal(double x_init, double y_init, double z_init);

        Normal operator+(const Normal& other) const;
        Normal& operator+=(const Normal& other);
        Normal operator-(const Normal& other) const;
        Normal& operator-=(const Normal& other);

        Normal operator*(const double scalar) const;
        Normal& operator*=(const double scalar);
        Normal operator/(const double scalar) const;
        Normal& operator/=(const double scalar);

        double length_squared() const;
        double length() const;
    };

    Normal abs(const Normal& n);
    Normal normalize(const Normal& n);
    double dot (const Normal& n, const Vector3& v);
    Normal operator*(double a, const Normal& n);
}

#endif