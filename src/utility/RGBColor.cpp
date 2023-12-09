// RGBColor class implementation

#include "RGBColor.hpp"

#include <cmath>

namespace RT {
RGBColor::RGBColor() : r(0.0), g(0.0), b(0.0) {}
RGBColor::RGBColor(float r, float g, float b) : r(r), g(g), b(b) {}

RGBColor RGBColor::operator+(const RGBColor& other) const
{
    return RGBColor(r + other.r, g + other.g, b + other.b);
}

RGBColor& RGBColor::operator+=(const RGBColor& other)
{
    r += other.r; g += other.g; b += other.b;
    return *this;
}

RGBColor RGBColor::operator*(const RGBColor& other) const
{
    return RGBColor(r*other.r, g*other.g, b*other.b);
}

RGBColor RGBColor::operator*(const float scalar) const
{
    return RGBColor(r * scalar, g * scalar, b * scalar);
}

RGBColor RGBColor::operator/(const float scalar) const
{
    return RGBColor(r / scalar, g / scalar, b / scalar);
}

RGBColor RGBColor::exp(const float scalar) const
{
    return RGBColor(std::pow(r,scalar), std::pow(g,scalar), std::pow(b,scalar));
}

RGBColor operator*(float scalar, const RGBColor& color)
{
    return color * scalar;
}

RGBColor maxToOne(const RGBColor& col)
{
    float max = std::max({col.r, col.g, col.b});
    return RGBColor(col.r / max, col.g / max, col.b / max);
}
} // namespace RT