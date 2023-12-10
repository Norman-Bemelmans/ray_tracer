// Vector3 implementation file

#include "Vector3.hpp"

#include <cmath>

namespace RT {
Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float x_init, float y_init, float z_init)
    : x(x_init), y(y_init), z(z_init) {}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x; y += other.y; z += other.z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3& Vector3::operator-=(const Vector3& other) {
    x -= other.x; y -= other.y; z -= other.z;
    return *this;
}

Vector3 Vector3::operator*(const float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3& Vector3::operator*=(const float scalar) {
    x *= scalar; y *= scalar; z *= scalar;
    return *this;
}

Vector3 Vector3::operator/(const float scalar) const {
    const float inv = 1 / scalar;
    return Vector3(x * inv, y * inv, z * inv);
}

Vector3& Vector3::operator/=(const float scalar) {
    const float inv = 1 / scalar;
    x *= inv; y *= inv; z *= inv;
    return *this;
}

Vector3 Vector3::operator-() const {
    return Vector3(-x, -y, -z);
}

float Vector3::lengthSquared() const {
    return x*x + y*y + z*z;
}

float Vector3::length() const {
    return std::sqrt(lengthSquared());
}

Vector3 abs(const Vector3& vec) {
    return Vector3(std::abs(vec.x), std::abs(vec.y), std::abs(vec.z));
}

Vector3 normalize(const Vector3& vec) {
    const float invLen = 1 / vec.length();
    return Vector3(vec.x * invLen, vec.y * invLen, vec.z * invLen);
}

float dot(const Vector3& a, const Vector3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 cross(const Vector3& a, const Vector3& b) {
    return Vector3(a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x);
}

Vector3 operator*(float scalar, const Vector3& vec) {
    return vec * scalar;
}
} // namespace RT