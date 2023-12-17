// Matte (derived from Material) class declarations.
// Matte is a perfect Lambertian reflector; there is no 
// specular component in the shading calculation.

#ifndef MATTE_HPP
#define MATTE_HPP

#include "Material.hpp"
#include "RGBColor.hpp"
#include "HitRecord.hpp"

#include <vector>

namespace RT {
class Matte : public Material {
    friend void test_def_ctor();
    friend void test_ctor();
    friend void test_shade();
public:
    Matte();

    // ctor takes ambient and diffuse reflection coefficients and 
    // the diffuse color as parameters:
    Matte(RGBColor ka, RGBColor kd);

    RGBColor shade(const HitRecord& hr, const Light& light) override;
private:
    // ambient reflection coefficient:
    RGBColor ka;
    // diffuse reflection coefficient:
    RGBColor kd;
};
} // namespace RT

#endif
