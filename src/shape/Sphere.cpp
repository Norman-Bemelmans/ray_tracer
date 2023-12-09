// Sphere class implementation.

#include "Sphere.hpp"
#include "MathUtils.hpp"

#include <algorithm>

namespace RT {
Sphere::Sphere(Point3 p, float r) : Shape(), center(p), radius(r) {}

bool Sphere::hit(Ray r, HitRecord* hitRecord) {
    double a = r.d.x*r.d.x + r.d.y*r.d.y + r.d.z*r.d.z;
    double b = 2*(r.o.x*r.d.x + r.o.y*r.d.y + r.o.z*r.d.z);
    double c = r.o.x*r.o.x + r.o.y*r.o.y + r.o.z*r.o.z;

    auto roots = quadratic(a, b, c);
    auto smallerRoot = std::min(roots.first, roots.second);

    if (roots.first > maxDouble) {
        return false;
    } else {
        hitRecord->hp = r.o + smallerRoot*r.d;
        hitRecord->sn = normalize(Normal((r.o + smallerRoot*r.d) - this->center));
        return true;
    }
}
} // namespace RT
