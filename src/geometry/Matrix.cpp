// Matrix class implementation.

#include <stdexcept>
#include <algorithm>

#include "Matrix.hpp"

namespace RT {

    Matrix::Matrix()
    {
        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 0.0;
        m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
    }

    Matrix::Matrix(float m00, float m01, float m02, float m03,
                   float m10, float m11, float m12, float m13,
                   float m20, float m21, float m22, float m23,
                   float m30, float m31, float m32, float m33)
    {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
        m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }

    Matrix Matrix::mult(const Matrix& other) const
    {
        return Matrix(m[0][0]*other.m[0][0] + m[0][1]*other.m[1][0] + m[0][2]*other.m[2][0] + m[0][3]*other.m[3][0],
                      m[0][0]*other.m[0][1] + m[0][1]*other.m[1][1] + m[0][2]*other.m[2][1] + m[0][3]*other.m[3][1],
                      m[0][0]*other.m[0][2] + m[0][1]*other.m[1][2] + m[0][2]*other.m[2][2] + m[0][3]*other.m[3][2],
                      m[0][0]*other.m[0][3] + m[0][1]*other.m[1][3] + m[0][2]*other.m[2][3] + m[0][3]*other.m[3][3],
                      m[1][0]*other.m[0][0] + m[1][1]*other.m[1][0] + m[1][2]*other.m[2][0] + m[1][3]*other.m[3][0],
                      m[1][0]*other.m[0][1] + m[1][1]*other.m[1][1] + m[1][2]*other.m[2][1] + m[1][3]*other.m[3][1],
                      m[1][0]*other.m[0][2] + m[1][1]*other.m[1][2] + m[1][2]*other.m[2][2] + m[1][3]*other.m[3][2],
                      m[1][0]*other.m[0][3] + m[1][1]*other.m[1][3] + m[1][2]*other.m[2][3] + m[1][3]*other.m[3][3],
                      m[2][0]*other.m[0][0] + m[2][1]*other.m[1][0] + m[2][2]*other.m[2][0] + m[2][3]*other.m[3][0],
                      m[2][0]*other.m[0][1] + m[2][1]*other.m[1][1] + m[2][2]*other.m[2][1] + m[2][3]*other.m[3][1],
                      m[2][0]*other.m[0][2] + m[2][1]*other.m[1][2] + m[2][2]*other.m[2][2] + m[2][3]*other.m[3][2],
                      m[2][0]*other.m[0][3] + m[2][1]*other.m[1][3] + m[2][2]*other.m[2][3] + m[2][3]*other.m[3][3],
                      m[3][0]*other.m[0][0] + m[3][1]*other.m[1][0] + m[3][2]*other.m[2][0] + m[3][3]*other.m[3][0],
                      m[3][0]*other.m[0][1] + m[3][1]*other.m[1][1] + m[3][2]*other.m[2][1] + m[3][3]*other.m[3][1],
                      m[3][0]*other.m[0][2] + m[3][1]*other.m[1][2] + m[3][2]*other.m[2][2] + m[3][3]*other.m[3][2],
                      m[3][0]*other.m[0][3] + m[3][1]*other.m[1][3] + m[3][2]*other.m[2][3] + m[3][3]*other.m[3][3]);
    }

    Matrix transpose(const Matrix& mat)
    {
        return Matrix(mat.m[0][0], mat.m[1][0], mat.m[2][0], mat.m[3][0],
                      mat.m[0][1], mat.m[1][1], mat.m[2][1], mat.m[3][1],
                      mat.m[0][2], mat.m[1][2], mat.m[2][2], mat.m[3][2],
                      mat.m[0][3], mat.m[1][3], mat.m[2][3], mat.m[3][3]);
    }

    // Avoid using this method for matrices that are scales, rotations, or 
    // translations or known compositions of these transformations.
    // Strongly prefer the Transform methods which are explicitly provided 
    // with an affine transformation and its inverse in those cases.
    Matrix inverse(const Matrix& m)
    {

        float det = m.m[0][0]*(m.m[1][1]*m.m[2][2] - m.m[2][1]*m.m[1][2]) -
                    m.m[0][1]*(m.m[1][0]*m.m[2][2] - m.m[2][0]*m.m[1][2]) +
                    m.m[0][2]*(m.m[1][0]*m.m[2][1] - m.m[2][0]*m.m[1][1]);
        float invDet = 1.0 / det;

        if (det == 0.0) {
            throw std::invalid_argument("Singular matrix supplied.\n");
        }

        float a = invDet*(m.m[1][1]*m.m[2][2] - m.m[1][2]*m.m[2][1]);
        float b = invDet*(m.m[0][2]*m.m[2][1] - m.m[0][1]*m.m[2][2]);
        float c = invDet*(m.m[0][1]*m.m[1][2] - m.m[0][2]*m.m[1][1]);
        float d = invDet*(m.m[1][2]*m.m[2][0] - m.m[1][0]*m.m[2][2]);
        float e = invDet*(m.m[0][0]*m.m[2][2] - m.m[0][2]*m.m[2][0]);
        float f = invDet*(m.m[0][2]*m.m[1][0] - m.m[0][0]*m.m[1][2]);
        float g = invDet*(m.m[1][0]*m.m[2][1] - m.m[1][1]*m.m[2][0]);
        float h = invDet*(m.m[0][1]*m.m[2][0] - m.m[0][0]*m.m[2][1]);
        float i = invDet*(m.m[0][0]*m.m[1][1] - m.m[0][1]*m.m[1][0]);

        float x = -(a*m.m[0][3] + b*m.m[1][3] + c*m.m[2][3]);
        float y = -(d*m.m[0][3] + e*m.m[1][3] + f*m.m[2][3]);
        float z = -(g*m.m[0][3] + h*m.m[1][3] + i*m.m[2][3]);

        return Matrix(a, b, c, x,
                      d, e, f, y,
                      g, h, i, z,
                      0.0, 0.0, 0.0, 1.0);
    }
}
