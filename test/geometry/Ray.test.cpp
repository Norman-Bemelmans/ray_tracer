// Ray class unit test.

#include "Ray.hpp"
#include "Point3.hpp"
#include "Vector3.hpp"

#include <cassert>
#include <iostream>

namespace RT {
void test_def_ctor()
{
    Ray test;
    assert(test.o.x == 0.0);
    assert(test.o.y == 0.0);
    assert(test.o.z == 0.0);
}

void test_ctor()
{
    Point3 blip(1.0, 2.0, 3.0);
    Vector3 blop(4.0, 5.0, 6.0);
    Ray test(blip, blop);
    assert(test.o.x == 1.0);
    assert(test.o.y == 2.0);
    assert(test.o.z == 3.0);
    assert(test.d.x == 4.0);
    assert(test.d.y == 5.0);
    assert(test.d.z == 6.0);
}

void test_fun_op()
{
    Point3 blip(1.0, 2.0, 3.0);
    Vector3 blop(4.0, 5.0, 6.0);
    Ray test(blip, blop);
    assert((test(2.0)).x == 9.0);
    assert((test(2.0)).y == 12.0);
    assert((test(2.0)).z == 15.0);
}
} // namespace RT

int main() {
    RT::test_def_ctor();
    RT::test_ctor();
    RT::test_fun_op();

    std::cout << "Ray class unit test successfully completed.\n";
    return 0;
}