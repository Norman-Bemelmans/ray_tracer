// Pinhole (camera derived class) unit test

#include <cmath>
#include <cassert>
#include <iostream>

#include "Pinhole.hpp"
#include "Camera.hpp"
#include "Transform.hpp"
#include "Vector3.hpp"
#include "Point3.hpp"

namespace RT {
    
    void test_def_ctor()
    {
        float epsilon = 0.00001;
        Pinhole c;

        assert(std::abs(c.ep.x - 0.0) < epsilon);
        assert(std::abs(c.ep.y - 0.0) < epsilon);
        assert(std::abs(c.ep.z - 0.0) < epsilon);
        assert(std::abs(c.vd.x - 0.0) < epsilon);
        assert(std::abs(c.vd.y - 0.0) < epsilon);
        assert(std::abs(c.vd.z - 1.0) < epsilon);
        assert(std::abs(c.up.x - 0.0) < epsilon);
        assert(std::abs(c.up.y + 1.0) < epsilon);
        assert(std::abs(c.up.z - 0.0) < epsilon);

        assert(std::abs(c.focLen - 1.0) < epsilon);

        assert(c.c2w.m.m[0][0] == 1.0); assert(c.c2w.m.m[0][1] == 0.0);
        assert(c.c2w.m.m[0][2] == 0.0); assert(c.c2w.m.m[0][3] == 0.0);
        assert(c.c2w.m.m[1][0] == 0.0); assert(c.c2w.m.m[1][1] == 1.0);
        assert(c.c2w.m.m[1][2] == 0.0); assert(c.c2w.m.m[1][3] == 0.0);
        assert(c.c2w.m.m[2][0] == 0.0); assert(c.c2w.m.m[2][1] == 0.0);
        assert(c.c2w.m.m[2][2] == 1.0); assert(c.c2w.m.m[2][3] == 0.0);
        assert(c.c2w.m.m[3][0] == 0.0); assert(c.c2w.m.m[3][1] == 0.0);
        assert(c.c2w.m.m[3][2] == 0.0); assert(c.c2w.m.m[3][3] == 1.0);

        assert(c.c2w.mInv.m[0][0] == 1.0); assert(c.c2w.mInv.m[0][1] == 0.0);
        assert(c.c2w.mInv.m[0][2] == 0.0); assert(c.c2w.mInv.m[0][3] == 0.0);
        assert(c.c2w.mInv.m[1][0] == 0.0); assert(c.c2w.mInv.m[1][1] == 1.0);
        assert(c.c2w.mInv.m[1][2] == 0.0); assert(c.c2w.mInv.m[1][3] == 0.0);
        assert(c.c2w.mInv.m[2][0] == 0.0); assert(c.c2w.mInv.m[2][1] == 0.0);
        assert(c.c2w.mInv.m[2][2] == 1.0); assert(c.c2w.mInv.m[2][3] == 0.0);
        assert(c.c2w.mInv.m[3][0] == 0.0); assert(c.c2w.mInv.m[3][1] == 0.0);
        assert(c.c2w.mInv.m[3][2] == 0.0); assert(c.c2w.mInv.m[3][3] == 1.0);

        assert(std::abs(c.vres - 300) < epsilon);
        assert(std::abs(c.hres - 400) < epsilon);
        assert(std::abs(c.t + 150) < epsilon);
        assert(std::abs(c.b - 150) < epsilon);
        assert(std::abs(c.l + 200) < epsilon);
        assert(std::abs(c.r - 200) < epsilon);
    }

    void test_ctor()
    {
        float epsilon = 0.00001;
        Pinhole c(Point3(0.0, 0.0, 0.0), Point3(0.0, 0.0, 1.0), Vector3(0.0, -1.0, 0.0),
                  2.5, 900, 1600, -450.0, 450.0, -800, 800);

        assert(std::abs(c.ep.x - 0.0) < epsilon);
        assert(std::abs(c.ep.y - 0.0) < epsilon);
        assert(std::abs(c.ep.z - 0.0) < epsilon);
        assert(std::abs(c.vd.x - 0.0) < epsilon);
        assert(std::abs(c.vd.y - 0.0) < epsilon);
        assert(std::abs(c.vd.z - 1.0) < epsilon);
        assert(std::abs(c.up.x - 0.0) < epsilon);
        assert(std::abs(c.up.y + 1.0) < epsilon);
        assert(std::abs(c.up.z - 0.0) < epsilon);

        assert(std::abs(c.focLen - 2.5) < epsilon);

        assert(c.c2w.m.m[0][0] == -1.0); assert(c.c2w.m.m[0][1] == 0.0);
        assert(c.c2w.m.m[0][2] == 0.0); assert(c.c2w.m.m[0][3] == 0.0);
        assert(c.c2w.m.m[1][0] == 0.0); assert(c.c2w.m.m[1][1] == -1.0);
        assert(c.c2w.m.m[1][2] == 0.0); assert(c.c2w.m.m[1][3] == 0.0);
        assert(c.c2w.m.m[2][0] == 0.0); assert(c.c2w.m.m[2][1] == 0.0);
        assert(c.c2w.m.m[2][2] == 1.0); assert(c.c2w.m.m[2][3] == 0.0);
        assert(c.c2w.m.m[3][0] == 0.0); assert(c.c2w.m.m[3][1] == 0.0);
        assert(c.c2w.m.m[3][2] == 0.0); assert(c.c2w.m.m[3][3] == 1.0);

        assert(c.c2w.mInv.m[0][0] == -1.0); assert(c.c2w.mInv.m[0][1] == 0.0);
        assert(c.c2w.mInv.m[0][2] == 0.0); assert(c.c2w.mInv.m[0][3] == 0.0);
        assert(c.c2w.mInv.m[1][0] == 0.0); assert(c.c2w.mInv.m[1][1] == -1.0);
        assert(c.c2w.mInv.m[1][2] == 0.0); assert(c.c2w.mInv.m[1][3] == 0.0);
        assert(c.c2w.mInv.m[2][0] == 0.0); assert(c.c2w.mInv.m[2][1] == 0.0);
        assert(c.c2w.mInv.m[2][2] == 1.0); assert(c.c2w.mInv.m[2][3] == 0.0);
        assert(c.c2w.mInv.m[3][0] == 0.0); assert(c.c2w.mInv.m[3][1] == 0.0);
        assert(c.c2w.mInv.m[3][2] == 0.0); assert(c.c2w.mInv.m[3][3] == 1.0);

        assert(std::abs(c.vres - 900) < epsilon);
        assert(std::abs(c.hres - 1600) < epsilon);
        assert(std::abs(c.t + 450) < epsilon);
        assert(std::abs(c.b - 450) < epsilon);
        assert(std::abs(c.l + 800) < epsilon);
        assert(std::abs(c.r - 800) < epsilon);
    }

    void test_create_ray()
    {
        float epsilon = 0.00001;
        Pinhole p;

        Ray r = p.createRay(0, 0);

        assert(std::abs(r.o.x - 0.0) < epsilon);
        assert(std::abs(r.o.y - 0.0) < epsilon);
        assert(std::abs(r.o.z - 0.0) < epsilon);
        assert(std::abs(r.d.x + 199.5) < epsilon);
        assert(std::abs(r.d.y + 149.5) < epsilon);
        assert(std::abs(r.d.z - 1.0) < epsilon);
    }
}

int main()
{
    RT::test_def_ctor();
    RT::test_ctor();
    RT::test_create_ray();
    std::cout << "Pinhole class unit test successfully completed.\n";
    return 0;
}