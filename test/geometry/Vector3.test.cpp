// Vector3 class unit test

#include "Vector3.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

namespace RT {
void test_def_ctor()
{
    Vector3 test;
    assert(test.x == 0);
    assert(test.y == 0);
    assert(test.z == 0);
}

void test_ctor()
{
    Vector3 test(1.0, 2.0, 3.0);
    assert(test.x == 1.0);
    assert(test.y == 2.0);
    assert(test.z == 3.0);
}

void test_plus()
{
    Vector3 t1(1.0, 2.0, 3.0);
    Vector3 t2(4.0, 5.0, 6.0);
    Vector3 sum = t1+t2;
    assert(sum.x == 5.0);
    assert(sum.y == 7.0);
    assert(sum.z == 9.0);
}

void test_plus_eqs()
{
    Vector3 t1(1.0, 2.0, 3.0);
    Vector3 t2(4.0, 5.0, 6.0);
    t1+=t2;
    assert(t1.x == 5.0);
    assert(t1.y == 7.0);
    assert(t1.z == 9.0);
}

void test_minus()
{
    Vector3 t1(4.0, 5.0, 6.0);
    Vector3 t2(1.0, 2.0, 3.0);
    Vector3 diff = t2-t1;
    assert(diff.x == -3.0);
    assert(diff.y == -3.0);
    assert(diff.z == -3.0);
}

void test_minus_eqs()
{
    Vector3 t1(1.0, 2.0, 3.0);
    Vector3 t2(4.0, 5.0, 6.0);
    t2-=t1;
    assert(t2.x == 3.0);
    assert(t2.y == 3.0);
    assert(t2.z == 3.0);
}

void test_mult()
{
    double a = 2.5;
    Vector3 v(2.0, 4.0, 6.0);
    Vector3 scale = v*a;
    assert(scale.x == 5.0);
    assert(scale.y == 10.0);
    assert(scale.z == 15.0); 
}

void test_mult_eqs()
{
    double a = 2.0;
    Vector3 v(1.0, 2.0, 3.0);
    v*=a;
    assert(v.x == 2.0);
    assert(v.y == 4.0);
    assert(v.z == 6.0);
}

void test_div()
{
    double a = 2.0;
    Vector3 v(4.0, 5.0, 6.0);
    Vector3 div = v/a;
    assert(div.x == 2.0);
    assert(div.y == 2.5);
    assert(div.z == 3.0);
}

void test_div_eqs()
{
    double a = 3.0;
    Vector3 v(12.0, 15.0, 18.0);
    v/=a;
    assert(v.x == 4.0);
    assert(v.y == 5.0);
    assert(v.z == 6.0);
}

void test_negate()
{
    const double epsilon = 0.0001;
    Vector3 v(1.0, -3.2, 0.8);
    assert(std::abs((-v).x + 1.0) < epsilon);
    assert(std::abs((-v).y - 3.2) < epsilon);
    assert(std::abs((-v).z + 0.8) < epsilon);
}

void test_len_sqrd()
{
    Vector3 v(1.0, 2.0, 3.0);
    assert(v.lengthSquared() == 14.0);
}

void test_length()
{
    Vector3 v(1.0, 2.0, 2.0);
    assert(v.length() == 3.0);
}

void test_abs()
{
    double epsilon = 0.0001;
    Vector3 v(-1.2, 3.5, -0.8);
    Vector3 w = abs(v);
    assert(std::abs(w.x - 1.2) < epsilon);
    assert(std::abs(w.y - 3.5) < epsilon);
    assert(std::abs(w.z - 0.8) < epsilon);
}

void test_normalize()
{
    Vector3 v(4.0, 3.0, 0.0);
    const double epsilon = 0.001;
    assert(std::abs((normalize(v)).x - 0.8) < epsilon);
    assert(std::abs((normalize(v)).y - 0.6) < epsilon);
    assert(std::abs((normalize(v)).z - 0.0) < epsilon);
}

void test_dot()
{
    Vector3 w(1.0, 2.0, 3.0);
    Vector3 v(4.0, 5.0, 6.0);
    double z = dot( w, v );
    assert(z == 32.0);
}

void test_cross()
{
    Vector3 w(1.0, 2.0, 3.0);
    Vector3 v(4.0, 5.0, 6.0);
    assert((cross(w,v)).x == -3.0);
    assert((cross(w,v)).y == 6.0);
    assert((cross(w,v)).z == -3.0);
}

void test_mult2()
{
    double s = 2.0;
    Vector3 v(1.0, 2.0, 3.0);
    assert((s*v).x == 2.0);
    assert((s*v).y == 4.0);
    assert((s*v).z == 6.0);
}
} // namespace RT

int main() {
    RT::test_def_ctor();
    RT::test_ctor();
    RT::test_plus();
    RT::test_plus_eqs();
    RT::test_minus();
    RT::test_minus_eqs();
    RT::test_mult();
    RT::test_mult_eqs();
    RT::test_div();
    RT::test_div_eqs();
    RT::test_negate();
    RT::test_len_sqrd();
    RT::test_length();
    RT::test_abs();
    RT::test_normalize();
    RT::test_dot();
    RT::test_cross();
    RT::test_mult2();

    std::cout << "Vector3 class unit test successfully completed.\n";
    return 0;
}
