// Matrix class unit test.

#include <cmath>
#include <cassert>
#include <iostream>

#include "Matrix.hpp"

namespace RT {

    void test_def_ctor()
    {
        Matrix m;

        assert(m.m[0][0] == 1.0); assert(m.m[0][1] == 0.0);
        assert(m.m[0][2] == 0.0); assert(m.m[0][3] == 0.0);
        assert(m.m[1][0] == 0.0); assert(m.m[1][1] == 1.0);
        assert(m.m[1][2] == 0.0); assert(m.m[1][3] == 0.0);
        assert(m.m[2][0] == 0.0); assert(m.m[2][1] == 0.0);
        assert(m.m[2][2] == 1.0); assert(m.m[2][3] == 0.0);
        assert(m.m[3][0] == 0.0); assert(m.m[3][1] == 0.0);
        assert(m.m[3][2] == 0.0); assert(m.m[3][3] == 1.0);
    }

    void test_ctor()
    {
        const double epsilon = 0.0001;

        Matrix m(1.0, 1.0, 1.0, 2.5,
                 1.0, 2.0, -3.0, 11.1,
                 1.0, -3.0, 18.0, 0.4,
                 -0.3, -0.5, 4.23, 25.6);

        assert(m.m[0][0] == 1.0); assert(m.m[0][1] == 1.0);
        assert(m.m[0][2] == 1.0); assert(m.m[0][3] == 2.5);
        assert(m.m[1][0] == 1.0); assert(m.m[1][1] == 2.0);
        assert(m.m[1][2] == -3.0); assert(std::abs(m.m[1][3] - 11.1) < epsilon);
        assert(m.m[2][0] == 1.0); assert(m.m[2][1] == -3.0);
        assert(m.m[2][2] == 18.0); assert(std::abs(m.m[2][3] - 0.4) < epsilon);
        assert(std::abs(m.m[3][0] + 0.3) < epsilon); assert(m.m[3][1] == -0.5);
        assert(std::abs(m.m[3][2] - 4.23) < epsilon); assert(std::abs(m.m[3][3] - 25.6) < epsilon);
    }

    void test_mult()
    {
        const double epsilon = 0.0001;

        Matrix m1(1.0, 2.0, 3.0, 4.0,
                  5.0, 6.0, 7.0, 2.4,
                  3.1, 9.1, -11.2, 12.3,
                  5.25, -11.0, 24.0, 2.0);
        Matrix m2(2.1, 3.2, 1.5, -0.6,
                  3.5, 2.5, 4.5, 2.2,
                  9.1, 11.2, -0.2, 12.3,
                  1.0, 2.0, 3.0, 4.0);
        Matrix m3 = m1.mult(m2);

        assert(std::abs(m3.m[0][0] - 40.4) < epsilon); assert(std::abs(m3.m[0][1] - 49.8) < epsilon);
        assert(std::abs(m3.m[0][2] - 21.9) < epsilon); assert(std::abs(m3.m[0][3] - 56.7) < epsilon);
        assert(std::abs(m3.m[1][0] - 97.6) < epsilon); assert(std::abs(m3.m[1][1] - 114.2) < epsilon);
        assert(std::abs(m3.m[1][2] - 40.3) < epsilon); assert(std::abs(m3.m[1][3] - 105.9) < epsilon);
        assert(std::abs(m3.m[2][0] + 51.26) < epsilon); assert(std::abs(m3.m[2][1] + 68.17) < epsilon);
        assert(std::abs(m3.m[2][2] - 84.74) < epsilon); assert(std::abs(m3.m[2][3] + 70.4) < epsilon);
        assert(std::abs(m3.m[3][0] - 192.925) < epsilon); assert(std::abs(m3.m[3][1] - 262.1) < epsilon);
        assert(std::abs(m3.m[3][2] + 40.425) < epsilon); assert(std::abs(m3.m[3][3] - 275.85) < epsilon);
    }

    void test_transpose()
    {
        Matrix m(1.0, 2.0, 3.0, 4.0,
                 5.0, 6.0, 7.0, 8.0,
                 9.0, 10.0, 11.0, 12.0,
                 13.0, 14.0, 15.0, 16.0);

        assert(transpose(m).m[0][0] == 1.0); assert(transpose(m).m[0][1] == 5.0);
        assert(transpose(m).m[0][2] == 9.0); assert(transpose(m).m[0][3] == 13.0);
        assert(transpose(m).m[1][0] == 2.0); assert(transpose(m).m[1][1] == 6.0);
        assert(transpose(m).m[1][2] == 10.0); assert(transpose(m).m[1][3] == 14.0);
        assert(transpose(m).m[2][0] == 3.0); assert(transpose(m).m[2][1] == 7.0);
        assert(transpose(m).m[2][2] == 11.0); assert(transpose(m).m[2][3] == 15.0);
        assert(transpose(m).m[3][0] == 4.0); assert(transpose(m).m[3][1] == 8.0);
        assert(transpose(m).m[3][2] == 12.0); assert(transpose(m).m[3][3] == 16.0);
    }

    void test_inverse()
    {
        const double epsilon = 0.00001;

        Matrix m(1.0, -2.1, 4.5, 0.43,
                 1.4, 2.45, 13.15, -12.0,
                 1.0, 2.0, 3.0, 4.0,
                 0.0, 0.0, 0.0, 1.0);
        
        assert(std::abs(inverse(m).m[0][0] - 0.523915) < epsilon);
        assert(std::abs(inverse(m).m[0][1] + 0.423002) < epsilon);
        assert(std::abs(inverse(m).m[0][2] - 1.06829) < epsilon);
        assert(std::abs(inverse(m).m[0][3] + 9.57447) < epsilon);
        assert(std::abs(inverse(m).m[1][0] + 0.247443) < epsilon);
        assert(std::abs(inverse(m).m[1][1] - 0.0414708) < epsilon);
        assert(std::abs(inverse(m).m[1][2] - 0.189383) < epsilon);
        assert(std::abs(inverse(m).m[1][3] + 0.153484) < epsilon);
        assert(std::abs(inverse(m).m[2][0] + 0.009677) < epsilon);
        assert(std::abs(inverse(m).m[2][1] - 0.113354) < epsilon);
        assert(std::abs(inverse(m).m[2][2] + 0.149019) < epsilon);
        assert(std::abs(inverse(m).m[2][3] - 1.96048) < epsilon);
        assert(std::abs(inverse(m).m[3][0] - 0.0) < epsilon);
        assert(std::abs(inverse(m).m[3][1] - 0.0) < epsilon);
        assert(std::abs(inverse(m).m[3][2] - 0.0) < epsilon);
        assert(std::abs(inverse(m).m[3][3] - 1.0) < epsilon);

    }
}

int main()
{
    RT::test_def_ctor();
    RT::test_ctor();
    RT::test_mult();
    RT::test_transpose();
    RT::test_inverse();
    std::cout << "Matrix class unit test successfully completed.\n";
    return 0;
}