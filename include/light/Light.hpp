// Light (abstract class) declarations:

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Vector3.hpp"
#include "RGBColor.hpp"
#include "HitRecord.hpp"

namespace RT {
class Point3;

class Light {
    friend void test_def_ctor();
    friend void test_ctor();
public:
    Light();
    Light(const RGBColor& color);
    RGBColor color;
    virtual ~Light();

    // point-to-light direction:
    virtual Vector3 ptlDir(const Point3& point) const = 0;
};
} // namespace RT

#endif
