// Point3 class declarations.

#ifndef POINT3_HPP
#define POINT3_HPP

#include "Vector3.hpp"

namespace RT {

    class Point3 {
    public:
        double x;
        double y;
        double z;

        Point3();
        Point3(double x_init, double y_init, double z_init);

        Point3 operator+(const Vector3& v) const;
        Point3& operator+=(const Vector3& v);
        Point3 operator-(const Vector3& v) const;
        Point3& operator-=(const Vector3& v);
        Vector3 operator-(const Point3& p) const;
    };

    double dist(const Point3& p1, const Point3& p2);
    double squareDist(const Point3& p1, const Point3& p2);
}

#endif
