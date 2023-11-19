// Ray class declarations.

#ifndef RAY_HPP
#define RAY_HPP

#include "Vector3.hpp"
#include "Point3.hpp"

namespace RT { 
    class Ray {
    public:
        Point3 o;
        Vector3 d;

        Ray();
        Ray(const Point3& o_init, const Vector3& d_init);

        // Overloaded () operator provides the point on the ray
        // corresponding to a given t);
        Point3 operator()(float t);
    };
}

#endif
