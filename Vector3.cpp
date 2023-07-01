// Vector3 implementation file

#include "Vector3.h"
#include <cmath>

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

Vector3 Vector3::operator-()
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

Vector3 Vector3::normalize()
{
    const double invLen = 1 / length();
    return Vector3(x * invLen, y * invLen, z * invLen);
}

double Vector3::dot(Vector3 other)
{
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(Vector3 other)
{
    return Vector3(y * other.z - z * other.y,
                   z * other.x - x * other.z,
                   x * other.y - y * other.x);
}