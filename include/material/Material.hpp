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
class Point3;
class Normal;

class Material {
public:
    virtual RGBColor shade(const Point3& hitPoint, const Normal& normal, const Light* light) = 0;
};
} // namespace RT

#endif
