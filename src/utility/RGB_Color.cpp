// RGB_Color class implementation

#include <cmath>

#include "RGB_Color.hpp"

namespace RT {

    RGB_Color::RGB_Color() : r(0.0), g(0.0), b(0.0) {}
    RGB_Color::RGB_Color(float r, float g, float b) : r(r), g(g), b(b) {}

    RGB_Color RGB_Color::operator+(const RGB_Color& other) const
    {
        return RGB_Color(r + other.r, g + other.g, b + other.b);
    }

    RGB_Color& RGB_Color::operator+=(const RGB_Color& other)
    {
        r += other.r; g += other.g; b += other.b;
        return *this;
    }

    RGB_Color RGB_Color::operator*(const RGB_Color& other) const
    {
        return RGB_Color(r*other.r, g*other.g, b*other.b);
    }

    RGB_Color RGB_Color::operator*(const float scalar) const
    {
        return RGB_Color(r * scalar, g * scalar, b * scalar);
    }

    RGB_Color RGB_Color::operator/(const float scalar) const
    {
        return RGB_Color(r / scalar, g / scalar, b / scalar);
    }

    RGB_Color RGB_Color::exp(const float scalar) const
    {
        return RGB_Color(std::pow(r,scalar), std::pow(g,scalar), std::pow(b,scalar));
    }

    RGB_Color operator*(float scalar, const RGB_Color& color)
    {
        return color * scalar;
    }
}