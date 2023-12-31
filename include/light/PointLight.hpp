// Point_Light (derived from Light) declarations

#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP

#include "Light.hpp"
#include "RGBColor.hpp"
#include "Point3.hpp"
#include "Vector3.hpp"
#include "HitRecord.hpp"

namespace RT {
class Point3;
 
class PointLight : public Light {
    friend void test_def_ctor();
    friend void test_ctor();
public:
    PointLight();
    PointLight(RGBColor color_init, Point3 loc_init);

    Vector3 ptlDir(const Point3& point) const override;
private:
    // Location of point light.
    Point3 loc;
};
} // namespace RT

#endif
