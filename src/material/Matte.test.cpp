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
        const float epsilon = 0.00001;
        Matte test(0.1, 0.2, RGB_Color(0.5, 0.6, 0.7));
        assert(std::abs(test.ka - 0.1) < epsilon);
        assert(std::abs(test.kd - 0.2) < epsilon);
        assert(std::abs(test.cd.r - 0.5) < epsilon);
        assert(std::abs(test.cd.g - 0.6) < epsilon);
        assert(std::abs(test.cd.b - 0.7) < epsilon);
    }

    void test_shade()
    {
        const float epsilon = 0.00001;
        Hit_Record hitrec;
        std::vector<Light*> vec;
        Point_Light x;
        Point_Light y;
        Point_Light z;
        Point_Light* a = &x; 
        Point_Light* b = &y;
        Point_Light* c = &z;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        Matte test;
        assert(std::abs(test.shade(hitrec, vec).r - 1.0) < epsilon);
        assert(test.shade(hitrec, vec).r == 1.0);
        assert(test.shade(hitrec, vec).g == 1.0);
        assert(test.shade(hitrec, vec).b == 1.0);
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
