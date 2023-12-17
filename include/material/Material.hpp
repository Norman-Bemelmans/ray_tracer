// Material (abstract class) declaration
// Each derived class must provide a shade() method which computes 
// the radiance at a given pixel.

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Light.hpp"
#include "RGBColor.hpp"

#include <vector>

namespace RT {
class HitRecord;

class Material {
protected:
    virtual RGBColor shade(const HitRecord& hr,  const Light& light) = 0;
};
} // namespace RT

#endif
