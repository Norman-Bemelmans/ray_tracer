//Vector3.h
//Vector3 implements a 3-vector for ray tracing.

#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 
{
public:
    double x;
    double y;
    double z;

    Vector3();
    Vector3( double x_init, double y_init, double z_init);

    Vector3 operator+(const Vector3& other) const;
    Vector3& operator+=(const Vector3& other);
    Vector3 operator-(const Vector3& other) const;
    Vector3& operator-=(const Vector3& other);

    // multiplication of vector v and scalar s must be written v*s:
    Vector3 operator*(const double scalar) const;
    Vector3& operator*=(const double scalar);
    Vector3 operator/(const double scalar) const;
    Vector3& operator/=(const double scalar);

    //unary '-' changes the sign of a vector:
    Vector3 operator-();

    double length_squared() const;
    double length() const;

    Vector3 normalize();
    double dot_prod(Vector3 other);
    Vector3 cross_prod(Vector3 other);
};

#endif
