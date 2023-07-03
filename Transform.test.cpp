// Transform class unit test

#include <cmath>
#include <cassert>
#include <iostream>

#include "Transform.hpp"
#include "Vector3.hpp"

namespace RT {
    
    void test_def_ctor()
    {
        Transform t;
        assert(t.m[0][0] == 1.0); assert(t.m[0][1] == 0.0); assert(t.m[0][2] == 0.0);
        assert(t.m[1][0] == 0.0); assert(t.m[1][1] == 1.0); assert(t.m[1][2] == 0.0);
        assert(t.m[2][0] == 0.0); assert(t.m[2][1] == 0.0); assert(t.m[2][2] == 1.0);
        assert(t.det == 1.0);
        assert(t.invDet == 1.0);
    }

    void test_ctor_sing()
    {
        Transform t(1.0, 2.0, 3.0,
                    4.0, 5.0, 6.0,
                    7.0, 8.0, 9.0);
    }

    void test_ctor_gd()
    {
       Transform t(1.0, 1.0, 1.0,
                   1.0, 2.0, -3.0,
                   1.0, -3.0, 18.0);
        assert(t.m[0][0] == 1.0); assert(t.m[0][1] == 1.0); assert(t.m[0][2] == 1.0);
        assert(t.m[1][0] == 1.0); assert(t.m[1][1] == 2.0); assert(t.m[1][2] == -3.0);
        assert(t.m[2][0] == 1.0); assert(t.m[2][1] == -3.0); assert(t.m[2][2] == 18.0);
        assert(t.det == 1.0);
        assert(t.invDet == 1.0);
    }

    void test_inverse()
    {
        Transform t(1.0, 1.0, 1.0,
                    1.0, 2.0, -3.0,
                    1.0, -3.0, 18.0);
        assert((inverse(t)).m[0][0] == 27.0);
        assert((inverse(t)).m[0][1] == -21.0);
        assert((inverse(t)).m[0][2] == -5.0);
        assert((inverse(t)).m[1][0] == -21.0);
        assert((inverse(t)).m[1][1] == 17.0);
        assert((inverse(t)).m[1][2] == 4.0);
        assert((inverse(t)).m[2][0] == -5.0);
        assert((inverse(t)).m[2][1] == 4.0);
        assert((inverse(t)).m[2][2] == 1.0);
    }

    void test_mult_vec()
    {
        Transform A(1.0, 1.0, 1.0,
                   1.0, 2.0, -3.0,
                   1.0, -3.0, 2.0);
        Vector3 v(2.0, 4.0, 6.0);
        assert((A*v).x == 12.0);
        assert((A*v).y == -8.0);
        assert((A*v).z == 2.0);
    }

    void test_mult_tran()
    {
        const double epsilon = 0.001;
        Transform A(1.0, 1.0, 1.0,
                    1.0, 2.0, -3.0,
                    1.0, -3.0, 18.0);
        Transform B(27.0, -21.0, -5.0,
                    -21.0, 17.0, 4.0,
                    -5.0, 4.0, 1.0);
        assert((A*B).m[0][0] == 1.0);
        assert((A*B).m[0][1] == 0.0);
        assert((A*B).m[0][2] == 0.0);
        assert((A*B).m[1][0] == 0.0);
        assert((A*B).m[1][1] == 1.0);
        assert((A*B).m[1][2] == 0.0);
        assert((A*B).m[2][0] == 0.0);
        //assert(std::abs((A*B).m[2][0] - 0.0) < epsilon);
        assert((A*B).m[2][1] == 0.0);
        assert((A*B).m[2][2] == 1.0);
    }

}

int main()
{
    RT::test_def_ctor();
    //RT::test_ctor_sing();
    RT::test_ctor_gd();
    RT::test_mult_vec();
    RT::test_inverse();
    RT::test_mult_tran();
    std::cout << "Transform class unit test successfully completed.\n";
    return 0;
}
