// Ray class implementation.

#include "Ray.hpp"
#include "Point3.hpp"
#include "Vector3.hpp"

namespace RT {
Ray::Ray() : o(0, 0, 0), d(0, 0, 0) {}
Ray::Ray(const Point3& o_init, const Vector3& d_init)
    : o(o_init), d(d_init) {}

Point3 Ray::operator()(float t) {
    return Point3(o + t * d);
}
}  // namespacce RT
