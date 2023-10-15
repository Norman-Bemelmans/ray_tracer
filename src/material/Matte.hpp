// Matte (derived from Material) class declarations.
// Matte is a perfect Lambertian reflector; there is no 
// specular component in the shading calculation.

#ifndef MATTE_HPP
#define MATTE_HPP

#include <vector>

#include "Material.hpp"
#include "RGBColor.hpp"
#include "HitRecord.hpp"

namespace RT {

    class Matte : public Material {
        friend void test_def_ctor();
        friend void test_ctor();
        friend void test_shade();
    public:
        Matte();

        // ctor takes ambient and diffuse reflection coefficients and 
        // the diffuse color as parameters:
        Matte(float ka, float kd, RGBColor cd);

        RGBColor shade(const HitRecord& hr, const std::vector<Light*>& lv);
    private:
        // ambient reflection coefficient:
        float ka;
        // diffuse reflection coefficient:
        float kd;
        // diffuse color:
        RGBColor cd;
    };
}

#endif
