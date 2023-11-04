// Hit_Record class unit test

#include <cassert>
#include <iostream>
#include <type_traits>

#include "HitRecord.hpp"

namespace RT {

    void test_def_ctor()
    {
        HitRecord test;
        assert(test.hp.x == 0.0);
        assert(test.hp.y == 0.0);
        assert(test.hp.z == 0.0);
        assert(test.sn.x == 0.0);
        assert(test.sn.y == 0.0);
        assert(test.sn.z == 0.0);
    }
}

int main()
{
    RT::test_def_ctor();
    
    std::cout << "HitRecord class unit test successfully completed.\n";
    return 0;
}
