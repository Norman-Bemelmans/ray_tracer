// Vector3 implementation file

#include "Vector3.hpp"
#include <cmath>
namespace RT {

    Vector3::Vector3() : x(0), y(0), z(0) {}
    Vector3::Vector3(double x_init, double y_init, double z_init)
        : x(x_init), y(y_init), z(z_init) {}

    Vector3 Vector3::operator+(const Vector3& other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3& Vector3::operator+=(const Vector3& other)
    {
        x += other.x; y += other.y; z += other.z;
        return *this;
    }

    Vector3 Vector3::operator-(const Vector3& other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3& Vector3::operator-=(const Vector3& other)
    {
        x -= other.x; y -= other.y; z -= other.z;
        return *this;
    }

    Vector3 Vector3::operator*(const double scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3& Vector3::operator*=(const double scalar)
    {
        x *= scalar; y *= scalar; z *= scalar;
        return *this;
    }

    Vector3 Vector3::operator/(const double scalar) const
    {
        const double inv = 1 / scalar;
        return Vector3(x * inv, y * inv, z * inv);
    }

    Vector3& Vector3::operator/=(const double scalar)
    {
        const double inv = 1 / scalar;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }

    Vector3 Vector3::operator-() const
    {
        return Vector3(-x, -y, -z);
    }

    double Vector3::length_squared() const
    {
        return x*x + y*y + z*z;
    }

    double Vector3::length() const
    {
        return std::sqrt(length_squared());
    }

    Vector3 abs(const Vector3& vec)
    {
        return Vector3(std::abs(vec.x), std::abs(vec.y), std::abs(vec.z));
    }

    Vector3 normalize(const Vector3& vec)
    {
        const double invLen = 1 / vec.length();
        return Vector3(vec.x * invLen, vec.y * invLen, vec.z * invLen);
    }

    double dot(const Vector3& a, const Vector3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    Vector3 cross(const Vector3& a, const Vector3& b)
    {
        return Vector3(a.y * b.z - a.z * b.y,
                       a.z * b.x - a.x * b.z,
                       a.x * b.y - a.y * b.x);
    }

    Vector3 operator*(double scalar, const Vector3& vec)
    {
        return vec * scalar;
    }
}