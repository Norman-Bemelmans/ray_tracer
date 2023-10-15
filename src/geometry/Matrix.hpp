// Matrix class declarations.

#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace RT {

    class Matrix {
    public:
        float m[4][4];

        Matrix();
        Matrix(float m00, float m01, float m02, float m03,
               float m10, float m11, float m12, float m13,
               float m20, float m21, float m22, float m23,
               float m30, float m31, float m32, float m33);

        // other is the transform being transformed; the 
        // multiplication gives (*this)(other) as output.
        Matrix mult(const Matrix& other) const;
    };

        Matrix transpose(const Matrix& mat);
        Matrix inverse(const Matrix& m);
}

#endif
