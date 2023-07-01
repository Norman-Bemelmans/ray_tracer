// Vector3 class unit test

#include <cassert>
#include <iostream>

#include "Vector3.h"

void test_def_ctor()
{
    Vector3 test;
    assert(test.x == 0);
    assert(test.y == 0);
    assert(test.z == 0);
}

int main()
{
    test_def_ctor();
    std::cout << "Vector3 class unit test successfully completed.\n";
    std::cout << "Test of the test:\n"
    return 0;
}