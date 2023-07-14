// Ray class declarations.

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

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
        // corresponding to a parameter value t:
        Point3 operator()(float t);
    };
}

#endif
