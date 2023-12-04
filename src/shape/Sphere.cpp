// Sphere class implementation.

#include "Sphere.hpp"

#include <algorithm>

namespace RT {
    Sphere::Sphere(Point3 p, float r) : Shape(), center(p), radius(rad) {}

    bool Sphere::hit(Ray r, HitRecord* hitRecord) {
        double a = r.d.x*r.d.x + r.d.y*r.d.y + r.d.z*r.d.z;
        double b = 2*(r.o.x*r.d.x + r.o.y*r.d.y + r.o.z*r.d.z);
        double c = r.o.x*r.o.x + r.o.y*r.o.y + r.o.z*r.o.z;

        auto roots = MathUtils::quadratic(a, b, c);
        auto smallerRoot = std::min(roots.first, roots.second);

        if (roots.first > MathUtils::maxDouble) {
            return false;
        } else {
            hitRecord->hp = ray.o + smallerRoot*ray.d;
            hitRecord->sn = normalize(Normal((ray.o + smallerRoot*ray.d) - this->center));
        }
    }
}
