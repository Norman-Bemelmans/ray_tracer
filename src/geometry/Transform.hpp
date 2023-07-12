//Transform class header file.

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

// Including Vector3.h here because Vector3 must be declared in order to
// declare the Transform*vector method. Perhaps this could be changed to
// a forward declaration or these classes could be implemented with
// PIMPL. Dependency hell will do for now.
#include "Vector3.hpp"

namespace RT {

    class Transform {
        // The operator*() methods are declared as friends becasue they 
        // need access to Transform's private members.
        friend Transform inverse(const Transform& A);
        friend void test_def_ctor();
        friend void test_ctor_sing();
        friend void test_ctor_gd();
        friend void test_inverse();
        friend void test_mult_tran();
    private:
    // Transforms are implemented with doubles rather than floats.
    // This may need to change if performance suffers.
        double m[3][3];
        double det;
        double invDet;

    public:
        Transform();
        Transform(double m00, double m01, double m02,
                  double m10, double m11, double m12,
                  double m20, double m21, double m22);

        // Matrix multiplication is read from right to left; these operators
        // compute (this*v), or this transformation applied to v.
        Vector3 operator*(const Vector3& v);
        Transform operator*(const Transform& A);
        Point3 operator*(const Point3& p);
        Ray operator*(const Ray& r);
    };

        // Transform non-member functions (they are friends
        // of the class though):
        Transform inverse(const Transform& m);
}

#endif
