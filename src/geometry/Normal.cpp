// Normal class implementation file.

#include <cmath>

#include "Normal.hpp"
#include "Vector3.hpp"

namespace RT {

    Normal::Normal() : x(0), y(0), z(0) {}
    Normal::Normal(float x_init, float y_init, float z_init)
        : x(x_init), y(y_init), z(z_init) {}
    Normal::Normal(const Vector3& v) : x(v.x), y(v.y), z(v.z) {} 

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

    Normal Normal::operator*(const float scalar) const
    {
        return Normal(x * scalar, y * scalar, z * scalar);
    }

    Normal& Normal::operator*=(const float scalar)
    {
        x *= scalar; y *= scalar; z *= scalar;
        return *this;
    }

    Normal Normal::operator/(const float scalar) const
    {
        const float inv = 1 / scalar;
        return Normal(x * inv, y * inv, z * inv);
    }

    Normal& Normal::operator/=(const float scalar)
    {
        const float inv = 1 / scalar;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }

    float Normal::lengthSquared() const
    {
        return x*x + y*y + z*z;
    }

    float Normal::length() const
    {
        return std::sqrt(lengthSquared());
    }


    Normal abs(const Normal& n)
    {
        return Normal(std::abs(n.x), std::abs(n.y), std::abs(n.z));
    }

    Normal normalize(const Normal& n)
    {
        const float invLen = 1 / n.length();
        return Normal(n.x * invLen, n.y * invLen, n.z * invLen);
    }

    float dot(const Normal& n, const Vector3& v)
    {
            return n.x * v.x + n.y * v.y + n.z * v.z;
    }

    Normal operator*(float s, const Normal& n)
    {
        return n * s;
    }
}

