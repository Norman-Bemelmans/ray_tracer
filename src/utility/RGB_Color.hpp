// RGB_Color class declaration
// RGB colors are represented in a 3d color space, where each axis 
// (red, green, and blue) is normalized to the range [0,1], so we can think 
// of RGB colors as existing on a unit cube. 
// red = (1,0,0), green = (0,1,0), blue = (0,0,1), white = (1,1,1), 
// black = (0,0,0), grays = (a, a, a), 0 <= a <= 1

#ifndef RGB_COLOR_HPP
#define RGB_COLOR_HPP

namespace RT {

    class RGB_Color{
        friend void test_def_ctor();
        friend void test_ctor();
        friend void test_plus();
        friend void test_plus_eqs();
        friend void test_mult();
        friend void test_mult_scalar();
        friend void test_div();
        friend void test_exponent();
    private:
        float r;
        float g;
        float b;
    public:
        RGB_Color();
        RGB_Color(float r, float g, float b);

        RGB_Color operator+(const RGB_Color& other) const;
        RGB_Color& operator+=(const RGB_Color& other);
        RGB_Color operator*(const RGB_Color& other) const;
        RGB_Color operator*(const float scalar) const;
        RGB_Color operator/(const float scalar) const;
        RGB_Color exp(const float scalar) const;
    };

    // Including this one for commutativity so users can write a*color 
    // or color*a, where color is an RGB_Color instance and a is a scalar.
    RGB_Color operator*(float scalar, const RGB_Color& color);
}

#endif
