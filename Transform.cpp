//Transform class implementation

#include <stdexcept>

#include "Transform.hpp"
#include "Vector3.hpp"
#include "Point3.hpp"
#include "Ray.hpp"

namespace RT {

    Transform::Transform()
    {
        m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
        m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
        m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
        
        det = 1.0;
        invDet = 1.0;
    }

    Transform::Transform(double m00, double m01, double m02,
                         double m10, double m11, double m12,
                         double m20, double m21, double m22) 
    {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
        det = m00*(m11*m22 - m21*m12) -
              m01*(m10*m22 - m20*m12) +
              m02*(m10*m21 - m20*m11);
        if (det != 0.0) {
            invDet = 1 / det;
        }
        else {
            throw std::invalid_argument("Singular matrix supplied.\n");
        }
    }

    Vector3 Transform::operator*(const Vector3& v)
    {
        double x = v.x, y = v.y, z = v.z;
        return Vector3(m[0][0]*x + m[0][1]*y + m[0][2]*z,
                       m[1][0]*x + m[1][1]*y + m[1][2]*z,
                       m[2][0]*x + m[2][1]*y + m[2][2]*z);
    }

    Transform Transform::operator*(const Transform& A)
    {
        return Transform(m[0][0]*A.m[0][0] + m[0][1]*A.m[1][0] + m[0][2]*A.m[2][0],
                         m[0][0]*A.m[0][1] + m[0][1]*A.m[1][1] + m[0][2]*A.m[2][1],
                         m[0][0]*A.m[0][2] + m[0][1]*A.m[1][2] + m[0][2]*A.m[2][2],
                         m[1][0]*A.m[0][0] + m[1][1]*A.m[1][0] + m[1][2]*A.m[2][0],
                         m[1][0]*A.m[0][1] + m[1][1]*A.m[1][1] + m[1][2]*A.m[2][1],
                         m[1][0]*A.m[0][2] + m[1][1]*A.m[1][2] + m[1][2]*A.m[2][2],
                         m[2][0]*A.m[0][0] + m[2][1]*A.m[1][0] + m[2][2]*A.m[2][0],
                         m[2][0]*A.m[0][1] + m[2][1]*A.m[1][1] + m[2][2]*A.m[2][1],
                         m[2][0]*A.m[0][2] + m[2][1]*A.m[1][2] + m[2][2]*A.m[2][2]);
    }

    Point3 Transform::operator*(const Point3& p)
    {
        double x = p.x, y = p.y, z = p.z;
        return Point3(m[0][0]*x + m[0][1]*y + m[0][2]*z,
                      m[1][0]*x + m[1][1]*y + m[1][2]*z,
                      m[2][0]*x + m[2][1]*y + m[2][2]*z);
    }

    Ray Transform::operator*(const Ray& r)
    {

    }

    Transform inverse(const Transform& A)
    {
        return Transform(A.invDet*(A.m[1][1]*A.m[2][2] - A.m[1][2]*A.m[2][1]),
                         A.invDet*(A.m[0][2]*A.m[2][1] - A.m[0][1]*A.m[2][2]),
                         A.invDet*(A.m[0][1]*A.m[1][2] - A.m[0][2]*A.m[1][1]),
                         A.invDet*(A.m[1][2]*A.m[2][0] - A.m[1][0]*A.m[2][2]),
                         A.invDet*(A.m[0][0]*A.m[2][2] - A.m[0][2]*A.m[2][0]),
                         A.invDet*(A.m[0][2]*A.m[1][0] - A.m[0][0]*A.m[1][2]),
                         A.invDet*(A.m[1][0]*A.m[2][1] - A.m[1][1]*A.m[2][0]),
                         A.invDet*(A.m[0][1]*A.m[2][0] - A.m[0][0]*A.m[2][1]),
                         A.invDet*(A.m[0][0]*A.m[1][1] - A.m[0][1]*A.m[1][0]));
    }
}
