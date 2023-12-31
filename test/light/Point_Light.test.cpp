// Point_Light class unit test

#include "PointLight.hpp"
#include "Light.hpp"
#include "RGBColor.hpp"
#include "Point3.hpp"
#include "HitRecord.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

namespace RT {
void test_def_ctor()
{
    PointLight test;
    assert(test.color.r == 1.0);
    assert(test.color.g == 1.0);
    assert(test.color.b == 1.0);

    assert(test.loc.x == 0.0);
    assert(test.loc.y == 0.0);
    assert(test.loc.z == 0.0);
}

void test_ctor()
{
    PointLight test(RGBColor(0.5, 0.5, 0.5), (Point3(1.0, 2.0, 3.0)));
    assert(test.color.r == 0.5);
    assert(test.color.g == 0.5);
    assert(test.color.b == 0.5);

    assert(test.loc.x == 1.0);
    assert(test.loc.y == 2.0);
    assert(test.loc.z == 3.0);
}
} // namespace RT

int main() {
    RT::test_def_ctor();
    RT::test_ctor();

    std::cout << "PointLight class unit test successfully completed.\n";
    return 0;
}
