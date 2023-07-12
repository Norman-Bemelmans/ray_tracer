// Point3 class implementation file.

#include "Point3.hpp"
#include "Vector3.hpp"

namespace RT {
    
    Point3::Point3() : x(0), y(0), z(0) {}
    Point3::Point3(double x_init, double y_init, double z_init)
        : x(x_init), y(y_init), z(z_init) {}

    Point3 Point3::operator+(const Vector3& v) const
    {
        return Point3(x + v.x, y + v.y, z + v.z);
    }

    Point3& Point3::operator+=(const Vector3& v)
    {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    Point3 Point3::operator-(const Vector3& v) const
    {
        return Point3(x - v.x, y - v.y, z - v.z);
    }

    Point3& Point3::operator-=(const Vector3& v)
    {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }

    Vector3 Point3::operator-(const Point3& p) const
    {
        return Vector3(x - p.x, y - p.y, z - p.z);
    }


    double dist(const Point3& p1, const Point3& p2)
    {
        return (p1 - p2).length();
    }

    double squareDist(const Point3& p1, const Point3& p2)
    {
        return (p1 - p2).length_squared();
    }
}