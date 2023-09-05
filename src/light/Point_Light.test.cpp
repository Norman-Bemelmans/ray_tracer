// Point_Light class unit test

#include <cmath>
#include <cassert>
#include <iostream>

#include "Point_Light.hpp"
#include "Light.hpp"
#include "RGB_Color.hpp"
#include "Point3.hpp"
#include "Hit_Record.hpp"

namespace RT {

    void test_def_ctor()
    {
        Point_Light test;
        assert(test.color.r == 1.0);
        assert(test.color.g == 1.0);
        assert(test.color.b == 1.0);

        assert(test.loc.x == 1.0);
        assert(test.loc.y == 1.0);
        assert(test.loc.z == 1.0);
    }

    void test_ctor()
    {
        Point_Light test(RGB_Color(0.5, 0.5, 0.5), (Point3(1.0, 2.0, 3.0)));
        assert(test.color.r == 0.5);
        assert(test.color.g == 0.5);
        assert(test.color.b == 0.5);

        assert(test.loc.x == 1.0);
        assert(test.loc.y == 2.0);
        assert(test.loc.z == 3.0);
    }
}

int main()
{
    RT::test_def_ctor();
    RT::test_ctor();

    std::cout << "Point_Light class unit test successfully completed.\n";
    return 0;
}
