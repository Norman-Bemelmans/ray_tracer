// Point3 class unit test.

#include <cmath>
#include <cassert>
#include <iostream>

#include "Point3.hpp"
#include "Vector3.hpp"

namespace RT {

    void test_def_ctor()
    {
        Point3 test;
        assert(test.x == 0);
        assert(test.y == 0);
        assert(test.z == 0);
    }

    void test_ctor()
    {
        Point3 test(1.0, 2.0, 3.0);
        assert(test.x == 1.0);
        assert(test.y == 2.0);
        assert(test.z == 3.0);
    }

    void test_plus()
    {
        Point3 p1(1.0, 2.0, 3.0);
        Vector3 p2(4.0, 5.0, 6.0);
        Point3 sum = p1+p2;
        assert(sum.x == 5.0);
        assert(sum.y == 7.0);
        assert(sum.z == 9.0);
    }

    void test_plus_eqs()
    {
        Point3 p1(1.0, 2.0, 3.0);
        Vector3 p2(4.0, 5.0, 6.0);
        p1+=p2;
        assert(p1.x == 5.0);
        assert(p1.y == 7.0);
        assert(p1.z == 9.0);
    }

    void test_minus()
    {
        Point3 p1(4.0, 5.0, 6.0);
        Vector3 p2(1.0, 2.0, 3.0);
        Point3 diff = p1-p2;
        assert(diff.x == 3.0);
        assert(diff.y == 3.0);
        assert(diff.z == 3.0);
    }

    void test_minus_eqs()
    {
        Point3 p1(1.0, 2.0, 3.0);
        Vector3 p2(4.0, 5.0, 6.0);
        p1-=p2;
        assert(p1.x == -3.0);
        assert(p1.y == -3.0);
        assert(p1.z == -3.0);
    }

    void test_p_minus_p()
    {
        Point3 p1(2.0, 12.0, 5.0);
        Point3 p2(-6.2, 11.0, 28.0);
        assert ((p1 - p2).x == 8.2);
        assert ((p1 - p2).y == 1.0);
        assert ((p1 - p2).z == -23.0);
    }

    void test_dist()
    {
        const double epsilon = 0.001;
        Point3 p1(5.0, 2.0, -1.0);
        Point3 p2(1.0, 3.0, -6.0);
        assert(std::abs(dist(p1, p2) - 6.4807407) < epsilon);
    }

    void test_sq_dist()
    {
        const double epsilon = 0.001;
        Point3 p1(5.0, 2.0, -1.0);
        Point3 p2(1.0, 3.0, -6.0);
        assert(std::abs(squareDist(p1, p2) - 42.0) < epsilon);
    }
}

int main()
{
    RT::test_def_ctor();
    RT::test_ctor();
    RT::test_plus();
    RT::test_plus_eqs();
    RT::test_minus();
    RT::test_minus_eqs();
    RT::test_p_minus_p();
    RT::test_dist();
    RT::test_sq_dist();

    std::cout << "Point3 class unit test successfully completed.\n";
    return 0;
}
