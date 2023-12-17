// Sphere (derived from shape) class interface.

#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Shape.hpp"
#include "Point3.hpp"
#include "Ray.hpp"
#include "Transform.hpp"

namespace RT {
class Sphere : public RT::Shape {
    friend void test_ctor();
public:
    Sphere(Point3 p, float r, Material* mat);
    bool hit(Ray r, HitRecord* hitRecord) override;
private:
    Point3 center;
    float radius;
    Transform worldToShape;
};
} // namespace RT

#endif
