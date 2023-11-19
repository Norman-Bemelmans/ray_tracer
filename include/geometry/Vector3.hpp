//Vector3.hpp
//Vector3 implements a 3-vector for ray tracing.

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace RT { 
    class Vector3 {
    public:
        float x;
        float y;
        float z;

        Vector3();
        Vector3( float x_init, float y_init, float z_init);

        Vector3 operator+(const Vector3& other) const;
        Vector3& operator+=(const Vector3& other);
        Vector3 operator-(const Vector3& other) const;
        Vector3& operator-=(const Vector3& other);

        Vector3 operator*(const float scalar) const;
        Vector3& operator*=(const float scalar);
        Vector3 operator/(const float scalar) const;
        Vector3& operator/=(const float scalar);

        // Unary '-' changes the sign of a vector:
        Vector3 operator-() const;

        float lengthSquared() const;
        float length() const;
    };

    // These methods have been re-implemented as non-friend
    // non-member functions. This supports encapsulation
    // and code reuse (methods can be templated to be used for
    // other types.)
    Vector3 abs(const Vector3& vec);
    Vector3 normalize(const Vector3& vec);
    float dot(const Vector3& a, const Vector3& b);
    Vector3 cross(const Vector3& a, const Vector3& b);
    Vector3 operator*(float scalar, const Vector3& vec);
}

#endif
