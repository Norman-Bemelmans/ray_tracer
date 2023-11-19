// Sphere (derived from shape) class interface.

#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Shape.hpp"
#include "Point3.hpp"
#include "Ray.hpp"

namespace RT {
    class Sphere : public RT::Shape {
    public:
        Sphere(Point3 p, float r);
        bool hit(Ray r);
    private:
        Point3 center;
        float radius;
    };
}

#endif
