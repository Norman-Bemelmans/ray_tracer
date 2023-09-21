// Matte (derived from Material) class declarations.
// Matte is a perfect Lambertian reflector; there is no 
// specular component in the shading calculation.

#ifndef MATTE_HPP
#define MATTE_HPP

#include <vector>

#include "Material.hpp"
#include "RGB_Color.hpp"
#include "Hit_Record.hpp"

namespace RT {

    class Matte : public Material {
        friend void test_def_ctor();
        friend void test_ctor();
        friend void test_shade();
    public:
        Matte();

        // ctor takes ambient and diffuse reflection coefficients and 
        // the diffuse color as parameters:
        Matte(float ka, float kd, RGB_Color cd);

        RGB_Color shade(const Hit_Record& hr, const std::vector<Light*>& lv);
    private:
        // ambient reflection coefficient:
        float ka;
        // diffuse reflection coefficient:
        float kd;
        // diffuse color:
        RGB_Color cd;
    };
}

#endif
