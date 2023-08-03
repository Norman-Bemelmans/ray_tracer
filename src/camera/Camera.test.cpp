// Camera class unit test.

#include <cmath>
#include <cassert>
#include <iostream>

#include "Camera.hpp"
#include "Transform.hpp"
#include "Vector3.hpp"
#include "Point3.hpp"

namespace RT {
    
    void test_def_ctor()
    {
        float epsilon = 0.00001;
        Camera c;

        assert(std::abs(c.ep.x - 0.0) < epsilon);
        assert(std::abs(c.ep.y - 0.0) < epsilon);
        assert(std::abs(c.ep.z - 0.0) < epsilon);
        assert(std::abs(c.vd.x - 0.0) < epsilon);
        assert(std::abs(c.vd.y - 0.0) < epsilon);
        assert(std::abs(c.vd.z - 1.0) < epsilon);
        assert(std::abs(c.up.x - 0.0) < epsilon);
        assert(std::abs(c.up.y + 1.0) < epsilon);
        assert(std::abs(c.up.z - 0.0) < epsilon);

        assert(c.c2w.m[0][0] == 1.0); assert(c.c2w.m[0][1] == 0.0);
        assert(c.c2w.m[0][2] == 0.0); assert(c.c2w.m[0][3] == 0.0);
        assert(c.c2w.m[1][0] == 0.0); assert(c.c2w.m[1][1] == 1.0);
        assert(c.c2w.m[1][2] == 0.0); assert(c.c2w.m[1][3] == 0.0);
        assert(c.c2w.m[2][0] == 0.0); assert(c.c2w.m[2][1] == 0.0);
        assert(c.c2w.m[2][2] == 1.0); assert(c.c2w.m[2][3] == 0.0);
        assert(c.c2w.m[3][0] == 0.0); assert(c.c2w.m[3][1] == 0.0);
        assert(c.c2w.m[3][2] == 0.0); assert(c.c2w.m[3][3] == 1.0);

        assert(c.c2w.mInv[0][0] == 1.0); assert(c.c2w.mInv[0][1] == 0.0);
        assert(c.c2w.mInv[0][2] == 0.0); assert(c.c2w.mInv[0][3] == 0.0);
        assert(c.c2w.mInv[1][0] == 0.0); assert(c.c2w.mInv[1][1] == 1.0);
        assert(c.c2w.mInv[1][2] == 0.0); assert(c.c2w.mInv[1][3] == 0.0);
        assert(c.c2w.mInv[2][0] == 0.0); assert(c.c2w.mInv[2][1] == 0.0);
        assert(c.c2w.mInv[2][2] == 1.0); assert(c.c2w.mInv[2][3] == 0.0);
        assert(c.c2w.mInv[3][0] == 0.0); assert(c.c2w.mInv[3][1] == 0.0);
        assert(c.c2w.mInv[3][2] == 0.0); assert(c.c2w.mInv[3][3] == 1.0);
    }
}

int main()
{
    RT::test_def_ctor();
    std::cout << "Camera class unit test successfully completed.\n";
    return 0;
}
