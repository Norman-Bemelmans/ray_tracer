// Point_Light (derived from Light) class declarations

#include "PointLight.hpp"
#include "Light.hpp"
#include "RGBColor.hpp"
#include "Point3.hpp"
#include "HitRecord.hpp"

namespace RT {
PointLight::PointLight() : Light(), loc(0.0, 0.0, 0.0) {}
PointLight::PointLight(RGBColor color_init, Point3 loc_init) : Light(color_init), loc(loc_init) {}

Vector3 PointLight::ptlDir(const HitRecord& hr) const {
    return Vector3(loc - hr.hp);
}
} // namespace RT
