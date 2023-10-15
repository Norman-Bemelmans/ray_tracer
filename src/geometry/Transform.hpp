//Transform class header file.

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

// Including these headers here because they must be declared in order to
// declare the respective Transform*class method. Perhaps this could be changed to
// a forward declaration or these classes could be implemented with
// PIMPL. Dependency hell will do for now.
#include "Matrix.hpp"
#include "Normal.hpp"
#include "Vector3.hpp"
#include "Point3.hpp"
#include "Ray.hpp"

namespace RT {

    class Transform {
        friend Transform transpose(const Transform& t);
        friend Transform inverse(const Transform& t);
        friend Transform scale(float a, float b, float c);
        friend Transform rot_x(float theta);
        friend Transform rot_y(float theta);
        friend Transform rot_z(float theta);
        friend Transform translate(const Vector3& v);
        friend Transform lookAt(const Point3& pos, const Point3& look, const Vector3& up);
        friend void test_def_ctor();
        friend void test_ctor();
        friend void test_ctor1();
        friend void test_ctor2();
        friend void test_transpose();
        friend void test_inverse();
        friend void test_trans_mult();
        friend void test_scale();
        friend void test_rotx();
        friend void test_roty();
        friend void test_rotz();
        friend void test_translate();
        friend void test_look_at();
    private:
        Matrix m;
        Matrix mInv;

    public:
        Transform();

        // Try to avoid using this constructor:
        Transform(float m00, float m01, float m02, float m03,
                  float m10, float m11, float m12, float m13,
                  float m20, float m21, float m22, float m23,
                  float m30, float m31, float m32, float m33);

        // Strongly prefer this one:
        Transform(const Matrix& mat, const Matrix& invMat);

        

        // Matrix multiplication is read from right to left; these operators
        // compute (this*v), or this transformation applied to v.
        Vector3 operator*(const Vector3& v) const;
        Transform operator*(const Transform& t) const;
        Point3 operator*(const Point3& p) const;
        Ray operator*(const Ray& r) const;
        Normal operator*(const Normal& n) const;
    };

    // Transform non-member functions (they are friends
    // of the class though):
    Transform transpose(const Transform& t);
    Transform inverse(const Transform& t);
    Transform scale(float a, float b, float c);
    Transform rot_x(float theta);
    Transform rot_y(float theta);
    Transform rot_z(float theta);
    Transform translate(const Vector3& v);

    // look_at() orients the camera in world space: the difference between the
    // first two parameters gives a vector between the camera and the object
    // to be looked at and the final parameter gives the up direction.
    // These data are sufficient to orient the camera in space.
    Transform lookAt(const Point3& pos, const Point3& look, const Vector3& up);
}

#endif
