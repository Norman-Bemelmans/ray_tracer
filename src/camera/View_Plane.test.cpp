// View_Plane class unit test

#include "View_Plane.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

namespace RT {

    void test_def_ctor()
    {
        const float epsilon = 0.00001;
        View_Plane test;
        assert(std::abs(test.vres - 300) < epsilon);
        assert(std::abs(test.hres - 400) < epsilon);
        assert(std::abs(test.t + 150.0) < epsilon);
        assert(std::abs(test.b - 150.0) < epsilon);
        assert(std::abs(test.l + 200.0) < epsilon);
        assert(std::abs(test.r - 200.0) < epsilon);
    }

    void test_ctor()
    {
        const float epsilon = 0.00001;
        View_Plane test(900, 1600, -450.0, 450.0, -800.0, 800.0);
        assert(std::abs(test.vres - 900) < epsilon);
        assert(std::abs(test.hres - 1600) < epsilon);
        assert(std::abs(test.t + 450.0) < epsilon);
        assert(std::abs(test.b - 450.0) < epsilon);
        assert(std::abs(test.l + 800.0) < epsilon);
        assert(std::abs(test.r - 800.0) < epsilon);
    }
}

int main()
{
    RT::test_def_ctor();
    RT::test_ctor();

    std::cout << "View_Plane class unit test successfully completed.\n";
    return 0;
}
