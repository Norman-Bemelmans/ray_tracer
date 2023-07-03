//Transform class implementation

#include <stdexcept>

#include "Transform.hpp"
#include "Vector3.hpp"

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

// The multiplication methods are implemented as left-multiplication;
// that is, Transform( B, A ) is the result of applying B to A.
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

    Vector3 operator*(const Transform& A, const Vector3& v)
    {
        return Vector3(A.m[0][0]*v.x + A.m[0][1]*v.y + A.m[0][2]*v.z,
                       A.m[1][0]*v.x + A.m[1][1]*v.y + A.m[1][2]*v.z,
                       A.m[2][0]*v.x + A.m[2][1]*v.y + A.m[2][2]*v.z);
    }

    Transform operator*(const Transform& B, const Transform& A)
    {
        return Transform(B.m[0][0]*A.m[0][0] + B.m[0][1]*A.m[1][0] + B.m[0][2]*A.m[2][0],
                         B.m[0][0]*A.m[0][1] + B.m[0][1]*A.m[1][1] + B.m[0][2]*A.m[2][1],
                         B.m[0][0]*A.m[0][2] + B.m[0][1]*A.m[1][2] + B.m[0][2]*A.m[2][2],
                         B.m[1][0]*A.m[0][0] + B.m[1][1]*A.m[1][0] + B.m[1][2]*A.m[2][0],
                         B.m[1][0]*A.m[0][1] + B.m[1][1]*A.m[1][1] + B.m[1][2]*A.m[2][1],
                         B.m[1][0]*A.m[0][2] + B.m[1][1]*A.m[1][2] + B.m[1][2]*A.m[2][2],
                         B.m[2][0]*A.m[0][0] + B.m[2][1]*A.m[1][0] + B.m[2][2]*A.m[2][0],
                         B.m[2][0]*A.m[0][1] + B.m[2][1]*A.m[1][1] + B.m[2][2]*A.m[2][1],
                         B.m[2][0]*A.m[0][2] + B.m[2][1]*A.m[1][2] + B.m[2][2]*A.m[2][2]);
    }
}
