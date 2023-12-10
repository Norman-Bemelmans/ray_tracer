// Sphere class implementation.

#include "Sphere.hpp"
#include "MathUtils.hpp"
#include "Transform.hpp"

#include <algorithm>

namespace RT {
Sphere::Sphere(Point3 p, float rad, Material* mat) : Shape(mat), center(p), radius(rad),
                                      worldToShape(1.0, 0.0, 0.0, -center.x,
                                                   0.0, 1.0, 0.0, -center.y,
                                                   0.0, 0.0, 1.0, -center.z,
                                                   0.0, 0.0, 0.0, 1.0) {}

bool Sphere::hit(Ray r, HitRecord* hitRecord) {
    // Convert r from world space to object space coordinates:
    r = worldToShape * r;

    double a = r.d.x*r.d.x + r.d.y*r.d.y + r.d.z*r.d.z;
    double b = 2*(r.o.x*r.d.x + r.o.y*r.d.y + r.o.z*r.d.z);
    double c = r.o.x*r.o.x + r.o.y*r.o.y + r.o.z*r.o.z - radius*radius;

    auto roots = quadratic(a, b, c);
    auto smallerRoot = std::min(roots.first, roots.second);

    if (roots.first > maxDouble) {
        return false;
    } else {
        // Converting r back to world coordinates:
        r = inverse(worldToShape) * r;
        hitRecord->hp = r.o + smallerRoot*r.d;
        hitRecord->sn = normalize(Normal((r.o + smallerRoot*r.d) - this->center));
        return true;
    }
}
} // namespace RT
