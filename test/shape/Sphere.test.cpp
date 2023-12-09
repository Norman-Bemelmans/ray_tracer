// Sphere class unit tests

#include "Sphere.hpp"
#include "Point3.hpp"
#include "MathUtils.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

namespace RT {
void test_ctor() {
    Point3 p(1.0, 2.0, 4.0);
    Sphere s(p, 1.0);

    assert(s.center.x == 1.0);
    assert(s.center.y == 2.0);
    assert(s.center.z == 4.0);
    assert(s.radius == 1.0);
}
} // namespace RT

int main() {
    RT::test_ctor();

    std::cout << "Sphere class unit test successfully completed.\n";
    return 0;
}
