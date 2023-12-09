//Transform class implementation

#include "Transform.hpp"
#include "Matrix.hpp"
#include "Vector3.hpp"
#include "Point3.hpp"
#include "Ray.hpp"
#include "Normal.hpp"

#include <cmath>

namespace RT {
Transform::Transform()
{
    m = Matrix();
    mInv = Matrix();
}

Transform::Transform(float m00, float m01, float m02, float m03,
                        float m10, float m11, float m12, float m13,
                        float m20, float m21, float m22, float m23,
                        float m30, float m31, float m32, float m33)
{
    m = Matrix(m00, m01, m02, m03,
                m10, m11, m12, m13,
                m20, m21, m22, m23,
                m30, m31, m32, m33);
    mInv = RT::inverse(m);
}

Transform::Transform(const Matrix& mat, const Matrix& invMat)
    : m(mat) , mInv(invMat) {}


Vector3 Transform::operator*(const Vector3& v) const
{
    double x = v.x, y = v.y, z = v.z;
    return Vector3(m.m[0][0]*x + m.m[0][1]*y + m.m[0][2]*z,
                    m.m[1][0]*x + m.m[1][1]*y + m.m[1][2]*z,
                    m.m[2][0]*x + m.m[2][1]*y + m.m[2][2]*z);
}

Transform Transform::operator*(const Transform& t) const
{
    return Transform(m.mult(t.m), t.mInv.mult(mInv));
}

Point3 Transform::operator*(const Point3& p) const
{
    double x = p.x, y = p.y, z = p.z;
    return Point3(m.m[0][0]*x + m.m[0][1]*y + m.m[0][2]*z + m.m[0][3],
                    m.m[1][0]*x + m.m[1][1]*y + m.m[1][2]*z + m.m[1][3],
                    m.m[2][0]*x + m.m[2][1]*y + m.m[2][2]*z + m.m[2][3]);
}

Ray Transform::operator*(const Ray& r) const
{
    return Ray((*this)*r.o, (*this)*r.d);
}

// Normals must be transformed by the inverse transpose
// of a transformation to preserve normality.
Normal Transform::operator*(const Normal& n) const
{
    float x = n.x, y = n.y, z = n.z;
    return Normal(mInv.m[0][0]*x + mInv.m[1][0]*y + mInv.m[2][0]*z,
                    mInv.m[0][1]*x + mInv.m[1][1]*y + mInv.m[2][1]*z,
                    mInv.m[0][2]*x + mInv.m[1][2]*y + mInv.m[2][2]*z);
}

Transform transpose(const Transform& t)
{
    return Transform(RT::transpose(t.m), RT::transpose(t.mInv));
}

Transform inverse(const Transform& t)
{
    return Transform(t.mInv, t.m);
}

Transform scale(float a, float b, float c)
{
    Matrix m(a, 0.0, 0.0, 0.0,
                0.0, b, 0.0, 0.0,
                0.0, 0.0, c, 0.0,
                0.0, 0.0, 0.0, 1.0);
    Matrix mInv(1/a, 0.0, 0.0, 0.0,
                0.0, 1/b, 0.0, 0.0,
                0.0, 0.0, 1/c, 0.0,
                0.0, 0.0, 0.0, 1.0);
    return Transform(m, mInv);
}

Transform rot_x(float theta)
{
    float cosTheta = std::cos(theta);
    float sinTheta = std::sin(theta);
    Matrix m(1.0, 0.0, 0.0, 0.0,
                0.0, cosTheta, -sinTheta, 0.0,
                0.0, sinTheta, cosTheta, 0.0,
                0.0, 0.0, 0.0, 1.0);
    Matrix mInv(1.0, 0.0, 0.0, 0.0,
                0.0, cosTheta, sinTheta, 0.0,
                0.0, -sinTheta, cosTheta, 0.0,
                0.0, 0.0, 0.0, 1.0);
    return Transform(m, mInv);
}

Transform rot_y(float theta)
{
    float cosTheta = std::cos(theta);
    float sinTheta = std::sin(theta);
    Matrix m(cosTheta, 0.0, sinTheta, 0.0,
                0.0, 1.0, 0.0, 0.0,
                -sinTheta, 0.0, cosTheta, 0.0,
                0.0, 0.0, 0.0, 1.0);
    Matrix mInv(cosTheta, 0.0, -sinTheta, 0.0,
                0.0, 1.0, 0.0, 0.0,
                sinTheta, 0.0, cosTheta, 0.0,
                0.0, 0.0, 0.0, 1.0);
    return Transform(m, mInv);
}

Transform rot_z(float theta)
{
    float cosTheta = std::cos(theta);
    float sinTheta = std::sin(theta);
    Matrix m(cosTheta, -sinTheta, 0.0, 0.0,
                sinTheta, cosTheta, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0);
    Matrix mInv(cosTheta, sinTheta, 0.0, 0.0,
                -sinTheta, cosTheta, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0);
    return Transform(m, mInv);
}

Transform translate(const Vector3& v)
{
    float x = v.x, y = v.y, z = v.z;
    Matrix m(1.0, 0.0, 0.0, x,
                0.0, 1.0, 0.0, y,
                0.0, 0.0, 1.0, z,
                0.0, 0.0, 0.0, 1.0);
    Matrix mInv(1.0, 0.0, 0.0, -x,
                0.0, 1.0, 0.0, -y,
                0.0, 0.0, 1.0, -z,
                0.0, 0.0, 0.0, 1.0);
    return Transform(m, mInv); 
}

Transform lookAt(const Point3& pos, const Point3& look, const Vector3& up)
{
    // view_dir computes the direction vector between the camera origin
    // and the object being viewed:
    Vector3 view_dir = normalize(look - pos);
    // The left vector is the cross product of the up vector and 
    // the view direction vector (so it points to the left):
    Vector3 left = normalize(cross(up, view_dir));
    // up_actual computes a vector that is orthogonal to both left and
    // view_dir so it is the true vector that points "up" in this
    // orthonormal coordinate frame:
    Vector3 up_actual = cross(view_dir, left);

    Matrix c2w;
    c2w.m[0][3] = pos.x; c2w.m[1][3] = pos.y;
    c2w.m[2][3] = pos.z, c2w.m[3][3] = 1.0;

    c2w.m[0][2] = view_dir.x; c2w.m[1][2] = view_dir.y;
    c2w.m[2][2] = view_dir.z; c2w.m[3][2] = 0.0;

    c2w.m[0][1] = up_actual.x; c2w.m[1][1] = up_actual.y;
    c2w.m[2][1] = up_actual.z; c2w.m[3][1] = 0.0;

    c2w.m[0][0] = left.x; c2w.m[1][0] = left.y;
    c2w.m[2][0] = left.z; c2w.m[3][0] = 0.0;

    return Transform(c2w, RT::inverse(c2w));
}
} // namespace RT
