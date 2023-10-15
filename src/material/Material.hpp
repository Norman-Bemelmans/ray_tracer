// Material (abstract class) declaration
// Each derived class must provide a shade() method which computes 
// the radiance at a given pixel.

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <vector>

#include "Light.hpp"
#include "RGBColor.hpp"

namespace RT {

    class HitRecord;

    class Material {
    protected:
        virtual RGBColor shade(const HitRecord& hr,  const std::vector<RT::Light*>& lv) = 0;
    };
}

#endif
