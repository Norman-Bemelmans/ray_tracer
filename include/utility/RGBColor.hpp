// RGBColor class declaration
// RGB colors are represented in a 3d color space, where each axis 
// (red, green, and blue) is normalized to the range [0,1], so we can think 
// of RGB colors as existing on a unit cube. 
// red = (1,0,0), green = (0,1,0), blue = (0,0,1), white = (1,1,1), 
// black = (0,0,0), grays = (a, a, a), 0 <= a <= 1

#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP

#include <algorithm>

namespace RT {
    class RGBColor{
    public:
        float r;
        float g;
        float b;

        RGBColor();
        RGBColor(float r, float g, float b);

        RGBColor operator+(const RGBColor& other) const;
        RGBColor& operator+=(const RGBColor& other);
        RGBColor operator*(const RGBColor& other) const;
        RGBColor operator*(const float scalar) const;
        RGBColor operator/(const float scalar) const;
        RGBColor exp(const float scalar) const;
    };

    // Including this one for commutativity so users can write a*color 
    // or color*a, where color is an RGB_Color instance and a is a scalar.
    RGBColor operator*(float scalar, const RGBColor& color);

    // max_to_one handles out-of-gamut colors. It divides all color channels by the value 
    // of the max channel so that the RGB_Color has no channel higher than one.
    RGBColor maxToOne(const RGBColor& col);
}

#endif
