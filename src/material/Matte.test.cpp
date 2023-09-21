// Matte (derived from Material) class unit test

#include <vector>
#include <cassert>
#include <iostream>

#include "Matte.hpp"
#include "Material.hpp"
#include "RGB_Color.hpp"
#include "Hit_Record.hpp"
#include "Light.hpp"
#include "Point_Light.hpp"

namespace RT {

    void test_def_ctor()
    {
        Matte test;
        assert(test.ka == 1.0);
        assert(test.kd == 1.0);
        assert(test.cd.r == 0.5);
        assert(test.cd.g == 0.5);
        assert(test.cd.b == 0.5);
    }

    void test_ctor()
    {
        Matte test(0.1, 0.2, RGB_Color(0.5, 0.6, 0.7));
        assert(test.ka == 0.1);
        assert(test.kd == 0.2);
        assert(test.cd.r == 0.5);
        assert(test.cd.g == 0.6);
        assert(test.cd.b == 0.7);
    }

    void test_shade()
    {
        std::vector<Light> vec = {Point_Light a, Point_Light b, Point_Light c};
        Matte test;
        assert(test.shade().r == 1.0);
        assert(test.shade().g == 1.0);
        assert(test.shade().b == 1.0);
    }
}

int main()
{
    RT::test_def_ctor();
    RT::test_ctor();
    RT::test_shade();

    std::cout << "Matte class unit test successfully completed.\n";
    return 0;
}
