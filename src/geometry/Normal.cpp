// Normal class implementation file.

#include <cmath>

#include "Normal.hpp"
#include "Vector3.hpp"

namespace RT {

    Normal::Normal() : x(0), y(0), z(0) {}
    Normal::Normal(double x_init, double y_init, double z_init)
        : x(x_init), y(y_init), z(z_init) {}

    Normal Normal::operator+(const Normal& other) const
    {
        return Normal(x + other.x, y + other.y, z + other.z);
    }

    Normal& Normal::operator+=(const Normal& other)
    {
        x += other.x; y += other.y; z += other.z;
        return *this;
    }

    Normal Normal::operator-(const Normal& other) const
    {
        return Normal(x - other.x, y - other.y, z - other.z);
    }

    Normal& Normal::operator-=(const Normal& other)
    {
        x -= other.x; y -= other.y; z -= other.z;
        return *this;
    }

    Normal Normal::operator*(const double scalar) const
    {
        return Normal(x * scalar, y * scalar, z * scalar);
    }

    Normal& Normal::operator*=(const double scalar)
    {
        x *= scalar; y *= scalar; z *= scalar;
        return *this;
    }

    Normal Normal::operator/(const double scalar) const
    {
        const double inv = 1 / scalar;
        return Normal(x * inv, y * inv, z * inv);
    }

    Normal& Normal::operator/=(const double scalar)
    {
        const double inv = 1 / scalar;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }

    double Normal::length_squared() const
    {
        return x*x + y*y + z*z;
    }

    double Normal::length() const
    {
        return std::sqrt(length_squared());
    }


    Normal abs(const Normal& n)
    {
        return Normal(std::abs(n.x), std::abs(n.y), std::abs(n.z));
    }

    Normal normalize(const Normal& n)
    {
        const double invLen = 1 / n.length();
        return Normal(n.x * invLen, n.y * invLen, n.z * invLen);
    }

    double dot(const Normal& n, const Vector3& v)
    {
            return n.x * v.x + n.y * v.y + n.z * v.z;
    }

    Normal operator*(double s, const Normal& n)
    {
        return n * s;
    }
}

