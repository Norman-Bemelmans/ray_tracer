//Vector3.h
//Vector3 implements a 3-vector for ray tracing.

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace RT {
    
    class Vector3 {
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

        // Multiplication of vector v and scalar s must be written v*s:
        Vector3 operator*(const double scalar) const;
        Vector3& operator*=(const double scalar);
        Vector3 operator/(const double scalar) const;
        Vector3& operator/=(const double scalar);

        // Unary '-' changes the sign of a vector:
        Vector3 operator-() const;

        double length_squared() const;
        double length() const;
    };

    // These methods have been re-implemented as non-friend
    // non-member functions. This supports encapsulation
    // and code reuse (methods can be templated to be used for
    // other types.)
    Vector3 abs(const Vector3& vec);
    Vector3 normalize(const Vector3& vec);
    double dot(const Vector3& a, const Vector3& b);
    Vector3 cross(const Vector3& a, const Vector3& b);
}

#endif
