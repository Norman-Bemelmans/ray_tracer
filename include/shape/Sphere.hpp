// Sphere (derived from shape) class interface.

#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Shape.hpp"
#include "Point3.hpp"
#include "Ray.hpp"

namespace RT {
    class Sphere : public RT::Shape {
    public:
    Sphere(Point3 p, float radius);
    hit(Ray r);
    };
}
