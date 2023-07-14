// Point3 class declarations.

#ifndef POINT3_HPP
#define POINT3_HPP

#include "Vector3.hpp"

namespace RT {

    class Point3 {
    public:
        float x;
        float y;
        float z;

        Point3();
        Point3(float x_init, float y_init, float z_init);

        Point3 operator+(const Vector3& v) const;
        Point3& operator+=(const Vector3& v);
        Point3 operator-(const Vector3& v) const;
        Point3& operator-=(const Vector3& v);
        Vector3 operator-(const Point3& p) const;
    };

    float dist(const Point3& p1, const Point3& p2);
    float squareDist(const Point3& p1, const Point3& p2);
}

#endif
