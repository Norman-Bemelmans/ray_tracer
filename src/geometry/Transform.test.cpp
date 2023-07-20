// Transform class unit test

#include <cmath>
#include <cassert>
#include <iostream>

#include "Transform.hpp"
#include "Matrix.hpp"
#include "Vector3.hpp"
#include "Point3.hpp"
#include "Ray.hpp"
#include "Normal.hpp"


namespace RT {
    
    void test_def_ctor()
    {
        Transform t;

        assert(t.m.m[0][0] == 1.0); assert(t.m.m[0][1] == 0.0);
        assert(t.m.m[0][2] == 0.0); assert(t.m.m[0][3] == 0.0);
        assert(t.m.m[1][0] == 0.0); assert(t.m.m[1][1] == 1.0);
        assert(t.m.m[1][2] == 0.0); assert(t.m.m[1][3] == 0.0);
        assert(t.m.m[2][0] == 0.0); assert(t.m.m[2][1] == 0.0);
        assert(t.m.m[2][2] == 1.0); assert(t.m.m[2][3] == 0.0);
        assert(t.m.m[3][0] == 0.0); assert(t.m.m[3][1] == 0.0);
        assert(t.m.m[3][2] == 0.0); assert(t.m.m[3][3] == 1.0);

        assert(t.mInv.m[0][0] == 1.0); assert(t.mInv.m[0][1] == 0.0);
        assert(t.mInv.m[0][2] == 0.0); assert(t.mInv.m[0][3] == 0.0);
        assert(t.mInv.m[1][0] == 0.0); assert(t.mInv.m[1][1] == 1.0);
        assert(t.mInv.m[1][2] == 0.0); assert(t.mInv.m[1][3] == 0.0);
        assert(t.mInv.m[2][0] == 0.0); assert(t.mInv.m[2][1] == 0.0);
        assert(t.mInv.m[2][2] == 1.0); assert(t.mInv.m[2][3] == 0.0);
        assert(t.mInv.m[3][0] == 0.0); assert(t.mInv.m[3][1] == 0.0);
        assert(t.mInv.m[3][2] == 0.0); assert(t.mInv.m[3][3] == 1.0);
    }

    void test_ctor1()
    {
        const float epsilon = 0.0001;
        Transform t(1.0, -2.1, 4.5, 0.43,
                    1.4, 2.45, 13.15, -12.0,
                    1.0, 2.0, 3.0, 4.0,
                    0.0, 0.0, 0.0, 1.0);

        assert(std::abs(t.m.m[0][0] - 1.0) < epsilon);
        assert(std::abs(t.m.m[0][1] + 2.1) < epsilon);
        assert(std::abs(t.m.m[0][2] - 4.5) < epsilon);
        assert(std::abs(t.m.m[0][3] - 0.43) < epsilon);
        assert(std::abs(t.m.m[1][0] - 1.4) < epsilon);
        assert(std::abs(t.m.m[1][1] - 2.45) < epsilon);
        assert(std::abs(t.m.m[1][2] - 13.15) < epsilon);
        assert(std::abs(t.m.m[1][3] + 12.0) < epsilon);
        assert(std::abs(t.m.m[2][0] - 1.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 2.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 3.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 4.0) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 0.523915) < epsilon);
        assert(std::abs(t.mInv.m[0][1] + 0.423002) < epsilon);
        assert(std::abs(t.mInv.m[0][2] - 1.06829) < epsilon);
        assert(std::abs(t.mInv.m[0][3] + 9.57447) < epsilon);
        assert(std::abs(t.mInv.m[1][0] + 0.247443) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 0.0414708) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 0.189383) < epsilon);
        assert(std::abs(t.mInv.m[1][3] + 0.153484) < epsilon);
        assert(std::abs(t.mInv.m[2][0] + 0.009677) < epsilon);
        assert(std::abs(t.mInv.m[2][1] - 0.113354) < epsilon);
        assert(std::abs(t.mInv.m[2][2] + 0.149019) < epsilon);
        assert(std::abs(t.mInv.m[2][3] - 1.96048) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_ctor2()
    {
        const float epsilon = 0.0001;
        Matrix mat(1.0, -2.1, 4.5, 0.43,
                   1.4, 2.45, 13.15, -12.0,
                   1.0, 2.0, 3.0, 4.0,
                   0.0, 0.0, 0.0, 1.0);
        Matrix invMat(0.523915, -0.423002, 1.06829, -9.57447,
                      -0.247443, 0.0414708, 0.189383, -0.153484,
                      -0.009677, 0.113354, -0.149019, 1.96048,
                      0.0, 0.0, 0.0, 1.0);
        Transform t(mat, invMat);

        assert(std::abs(t.m.m[0][0] - 1.0) < epsilon);
        assert(std::abs(t.m.m[0][1] + 2.1) < epsilon);
        assert(std::abs(t.m.m[0][2] - 4.5) < epsilon);
        assert(std::abs(t.m.m[0][3] - 0.43) < epsilon);
        assert(std::abs(t.m.m[1][0] - 1.4) < epsilon);
        assert(std::abs(t.m.m[1][1] - 2.45) < epsilon);
        assert(std::abs(t.m.m[1][2] - 13.15) < epsilon);
        assert(std::abs(t.m.m[1][3] + 12.0) < epsilon);
        assert(std::abs(t.m.m[2][0] - 1.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 2.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 3.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 4.0) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 0.523915) < epsilon);
        assert(std::abs(t.mInv.m[0][1] + 0.423002) < epsilon);
        assert(std::abs(t.mInv.m[0][2] - 1.06829) < epsilon);
        assert(std::abs(t.mInv.m[0][3] + 9.57447) < epsilon);
        assert(std::abs(t.mInv.m[1][0] + 0.247443) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 0.0414708) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 0.189383) < epsilon);
        assert(std::abs(t.mInv.m[1][3] + 0.153484) < epsilon);
        assert(std::abs(t.mInv.m[2][0] + 0.009677) < epsilon);
        assert(std::abs(t.mInv.m[2][1] - 0.113354) < epsilon);
        assert(std::abs(t.mInv.m[2][2] + 0.149019) < epsilon);
        assert(std::abs(t.mInv.m[2][3] - 1.96048) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_vec_mult()
    {
        const float epsilon = 0.00001;
        Matrix mat(2.0, 0.0, 0.0, 1.1,
                   0.0, 4.0, 0.0, 1.2,
                   0.0, 0.0, 8.0, 1.3,
                   0.0, 0.0, 0.0, 1.0);
        Matrix invMat(0.5, 0.0, 0.0, -1.1,
                      0.0, 0.25, 0.0, -1.2,
                      0.0, 0.0, 0.125, -1.3,
                      0.0, 0.0, 0.0, 1.0);
        Transform t(mat, invMat);
        Vector3 in(1.0, 2.0, 3.0);
        Vector3 out = t*in;

        assert(std::abs(out.x - 2.0) < epsilon);
        assert(std::abs(out.y - 8.0) < epsilon);
        assert(std::abs(out.z - 24.0) < epsilon);
    }

    void test_trans_mult()
    {
        const float epsilon = 0.00001;
        Matrix mat1(2.0, 0.0, 0.0, 0.0,
                    0.0, 4.0, 0.0, 0.0,
                    0.0, 0.0, 8.0, 0.0,
                    0.0, 0.0, 0.0, 1.0);
        Matrix invMat1(0.5, 0.0, 0.0, 0.0,
                       0.0, 0.25, 0.0, 0.0,
                       0.0, 0.0, 0.125, 0.0,
                       0.0, 0.0, 0.0, 1.0);
        Matrix mat2(1.0, 0.0, 0.0, 0.0,
                    0.0, 0.0, -1.0, 0.0,
                    0.0, 1.0, 0.0, 0.0,
                    0.0, 0.0, 0.0, 1.0);
        Matrix invMat2(1.0, 0.0, 0.0, 0.0,
                       0.0, 0.0, 1.0, 0.0,
                       0.0, -1.0, 0.0, 0.0,
                       0.0, 0.0, 0.0, 1.0);
        Transform t1(mat1, invMat1);
        Transform t2(mat2, invMat2);
        Transform t = t1*t2;

        assert(std::abs(t.m.m[0][0] - 2.0) < epsilon);
        assert(std::abs(t.m.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][2] + 4.0) < epsilon);
        assert(std::abs(t.m.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 8.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 0.5) < epsilon);
        assert(std::abs(t.mInv.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 0.125) < epsilon);
        assert(std::abs(t.mInv.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][1] + 0.25) < epsilon);
        assert(std::abs(t.mInv.m[2][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_pt_mult()
    {
        const float epsilon = 0.00001;
        Matrix mat(1.0, 0.0, 0.0, 1.1,
                   0.0, 1.0, 0.0, 1.2,
                   0.0, 0.0, 1.0, 1.3,
                   0.0, 0.0, 0.0, 1.0);
        Matrix invMat(1.0, 0.0, 0.0, -1.1,
                      0.0, 1.0, 0.0, -1.2,
                      0.0, 0.0, 1.0, -1.3,
                      0.0, 0.0, 0.0, 1.0);
        Transform t(mat, invMat);
        Point3 in(1.0, 2.0, 3.0);
        Point3 out = t*in;

        assert(std::abs(out.x - 2.1) < epsilon);
        assert(std::abs(out.y - 3.2) < epsilon);
        assert(std::abs(out.z - 4.3) < epsilon);
    }

    void test_ray_mult()
    {
        const float epsilon = 0.00001;
        Matrix mat(2.0, 0.0, 0.0, 1.1,
                   0.0, 4.0, 0.0, 1.2,
                   0.0, 0.0, 8.0, 1.3,
                   0.0, 0.0, 0.0, 1.0);
        Matrix invMat(0.5, 0.0, 0.0, -1.1,
                      0.0, 0.25, 0.0, -1.2,
                      0.0, 0.0, 0.125, -1.3,
                      0.0, 0.0, 0.0, 1.0);
        Transform t(mat, invMat);
        Point3 p(1.0, 2.0, 3.0);
        Vector3 v(4.0, 5.0, 6.0);
        Ray in(p, v);
        Ray out = t*in;

        assert(std::abs(out.o.x - 3.1) < epsilon);
        assert(std::abs(out.o.y - 9.2) < epsilon);
        assert(std::abs(out.o.z - 25.3) < epsilon);
        assert(std::abs(out.d.x - 8.0) < epsilon);
        assert(std::abs(out.d.y - 20.0) < epsilon);
        assert(std::abs(out.d.z - 48.0) < epsilon);
    }

    void test_norm_mult()
    {
        const float epsilon = 0.00001;
        Matrix mat(2.0, 0.0, 0.0, 0.0,
                   0.0, 4.0, 0.0, 0.0,
                   0.0, 0.0, 8.0, 0.0,
                   0.0, 0.0, 0.0, 1.0);
        Matrix invMat(0.5, 0.0, 0.0, 0.0,
                      0.0, 0.25, 0.0, 0.0,
                      0.0, 0.0, 0.125, 0.0,
                      0.0, 0.0, 0.0, 1.0);
        Transform t(mat, invMat);
        Normal in(1.0, 2.0, 4.0);
        Normal out = t*in;

        assert(std::abs(out.x - 0.5) < epsilon);
        assert(std::abs(out.y - 0.5) < epsilon);
        assert(std::abs(out.z - 0.5) < epsilon);
    }

    void test_transpose()
    {
        const float epsilon = 0.0001;
        Matrix mat(1.0, 0.0, 0.0, 4.0,
                   0.0, 1.0, 0.0, 8.0,
                   0.0, 0.0, 1.0, 9.0,
                   0.0, 0.0, 0.0, 1.0);
        Matrix matInv(1.0, 0.0, 0.0, -4.0,
                      0.0, 1.0, 0.0, -8.0,
                      0.0, 0.0, 1.0, -9.0,
                      0.0, 0.0, 0.0, 1.0);
        Transform t(mat, matInv);
        Transform tt = RT::transpose(t);

        assert(std::abs(tt.m.m[0][0] - 1.0) < epsilon);
        assert(std::abs(tt.m.m[0][1] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[0][2] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[0][3] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[1][0] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[1][1] - 1.0) < epsilon);
        assert(std::abs(tt.m.m[1][2] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[1][3] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[2][0] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[2][1] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[2][2] - 1.0) < epsilon);
        assert(std::abs(tt.m.m[2][3] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[3][0] - 4.0) < epsilon);
        assert(std::abs(tt.m.m[3][1] - 8.0) < epsilon);
        assert(std::abs(tt.m.m[3][2] - 9.0) < epsilon);
        assert(std::abs(tt.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(tt.mInv.m[0][0] - 1.0) < epsilon);
        assert(std::abs(tt.mInv.m[0][1] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[0][2] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[0][3] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[1][0] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[1][1] - 1.0) < epsilon);
        assert(std::abs(tt.mInv.m[1][2] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[1][3] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[2][0] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[2][1] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[2][2] - 1.0) < epsilon);
        assert(std::abs(tt.mInv.m[2][3] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[3][0] + 4.0) < epsilon);
        assert(std::abs(tt.mInv.m[3][1] + 8.0) < epsilon);
        assert(std::abs(tt.mInv.m[3][2] + 9.0) < epsilon);
        assert(std::abs(tt.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_inverse()
    {
        const float epsilon = 0.0001;
        Matrix mat(1.0, 0.0, 0.0, 4.0,
                   0.0, 1.0, 0.0, 8.0,
                   0.0, 0.0, 1.0, 9.0,
                   0.0, 0.0, 0.0, 1.0);
        Matrix matInv(1.0, 0.0, 0.0, -4.0,
                      0.0, 1.0, 0.0, -8.0,
                      0.0, 0.0, 1.0, -9.0,
                      0.0, 0.0, 0.0, 1.0);
        Transform t(mat, matInv);
        Transform tt = RT::inverse(t);

        assert(std::abs(tt.m.m[0][0] - 1.0) < epsilon);
        assert(std::abs(tt.m.m[0][1] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[0][2] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[0][3] + 4.0) < epsilon);
        assert(std::abs(tt.m.m[1][0] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[1][1] - 1.0) < epsilon);
        assert(std::abs(tt.m.m[1][2] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[1][3] + 8.0) < epsilon);
        assert(std::abs(tt.m.m[2][0] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[2][1] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[2][2] - 1.0) < epsilon);
        assert(std::abs(tt.m.m[2][3] + 9.0) < epsilon);
        assert(std::abs(tt.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(tt.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(tt.mInv.m[0][0] - 1.0) < epsilon);
        assert(std::abs(tt.mInv.m[0][1] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[0][2] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[0][3] - 4.0) < epsilon);
        assert(std::abs(tt.mInv.m[1][0] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[1][1] - 1.0) < epsilon);
        assert(std::abs(tt.mInv.m[1][2] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[1][3] - 8.0) < epsilon);
        assert(std::abs(tt.mInv.m[2][0] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[2][1] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[2][2] - 1.0) < epsilon);
        assert(std::abs(tt.mInv.m[2][3] - 9.0) < epsilon);
        assert(std::abs(tt.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(tt.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_scale()
    {
        const float epsilon = 0.0001;
        Transform t = scale(2.0, 4.0, 8.0);

        assert(std::abs(t.m.m[0][0] - 2.0) < epsilon);
        assert(std::abs(t.m.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][1] - 4.0) < epsilon);
        assert(std::abs(t.m.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 8.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 0.5) < epsilon);
        assert(std::abs(t.mInv.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 0.25) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][2] - 0.125) < epsilon);
        assert(std::abs(t.mInv.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_rotx()
    {
        const float PI = 3.1415927;
        const float epsilon = 0.00001;
        Transform t = rot_x(PI / 2.0);

        assert(std::abs(t.m.m[0][0] - 1.0) < epsilon);
        assert(std::abs(t.m.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][2] + 1.0) < epsilon);
        assert(std::abs(t.m.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 1.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][1] + 1.0) < epsilon);
        assert(std::abs(t.mInv.m[2][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_roty()
    {
        const float PI = 3.1415927;
        const float epsilon = 0.00001;
        Transform t = rot_y(PI / 2.0);

        assert(std::abs(t.m.m[0][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][2] - 1.0) < epsilon);
        assert(std::abs(t.m.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][1] - 1.0) < epsilon);
        assert(std::abs(t.m.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][0] + 1.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][2] + 1.0) < epsilon);
        assert(std::abs(t.mInv.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][0] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_rotz()
    {
        const float PI = 3.1415927;
        const float epsilon = 0.00001;
        Transform t = rot_z(PI / 2.0);

        assert(std::abs(t.m.m[0][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][1] + 1.0) < epsilon);
        assert(std::abs(t.m.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][0] - 1.0) < epsilon);
        assert(std::abs(t.m.m[1][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 1.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][1] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][0] + 1.0) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][2] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[2][3] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_translate()
    {
        const float epsilon = 0.00001;
        const Vector3 v(1.1, 1.2, 1.3);
        Transform t = translate(v);

        assert(std::abs(t.m.m[0][0] - 1.0) < epsilon);
        assert(std::abs(t.m.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][3] - 1.1) < epsilon);
        assert(std::abs(t.m.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][1] - 1.0) < epsilon);
        assert(std::abs(t.m.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][3] - 1.2) < epsilon);
        assert(std::abs(t.m.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 1.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 1.3) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][3] + 1.1) < epsilon);
        assert(std::abs(t.mInv.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][3] + 1.2) < epsilon);
        assert(std::abs(t.mInv.m[2][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][2] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[2][3] + 1.3) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }

    void test_cam_init()
    {
        const float epsilon = 0.00001;
        Point3 pos(1.0, 3.0, 5.0);
        Point3 look(-3.0, 3.0, 5.0);
        Vector3 up(0.0, 1.0, 0.0);
        Transform t = cam_init(pos, look, up);

        assert(std::abs(t.m.m[0][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[0][2] - 1.0) < epsilon);
        assert(std::abs(t.m.m[0][3] + 5.0) < epsilon);
        assert(std::abs(t.m.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][1] - 1.0) < epsilon);
        assert(std::abs(t.m.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[1][3] + 3.0) < epsilon);
        assert(std::abs(t.m.m[2][0] + 1.0) < epsilon);
        assert(std::abs(t.m.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[2][3] - 1.0) < epsilon);
        assert(std::abs(t.m.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.m.m[3][3] - 1.0) < epsilon);

        assert(std::abs(t.mInv.m[0][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[0][2] + 1.0) < epsilon);
        assert(std::abs(t.mInv.m[0][3] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[1][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][1] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[1][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[1][3] - 3.0) < epsilon);
        assert(std::abs(t.mInv.m[2][0] - 1.0) < epsilon);
        assert(std::abs(t.mInv.m[2][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[2][3] - 5.0) < epsilon);
        assert(std::abs(t.mInv.m[3][0] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][1] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][2] - 0.0) < epsilon);
        assert(std::abs(t.mInv.m[3][3] - 1.0) < epsilon);
    }
}

int main()
{
    RT::test_def_ctor();
    RT::test_ctor1();
    RT::test_ctor2();
    RT::test_vec_mult();
    RT::test_trans_mult();
    RT::test_pt_mult();
    RT::test_ray_mult();
    RT::test_norm_mult();
    RT::test_transpose();
    RT::test_inverse();
    RT::test_scale();
    RT::test_rotx();
    RT::test_roty();
    RT::test_rotz();
    RT::test_translate();
    RT::test_cam_init();
    std::cout << "Transform class unit test successfully completed.\n";
    return 0;
}
