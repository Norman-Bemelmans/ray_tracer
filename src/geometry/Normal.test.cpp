// Normal class unit test.

#include <cmath>
#include <cassert>
#include <iostream>

#include "Normal.hpp"
#include "Vector3.hpp"

namespace RT {

    void test_def_ctor()
        {
            Normal test;
            assert(test.x == 0);
            assert(test.y == 0);
            assert(test.z == 0);
        }

        void test_ctor()
        {
            Normal test(1.0, 2.0, 3.0);
            assert(test.x == 1.0);
            assert(test.y == 2.0);
            assert(test.z == 3.0);
        }

        void test_plus()
        {
            Normal n1(1.0, 2.0, 3.0);
            Normal n2(4.0, 5.0, 6.0);
            Normal sum = n1+n2;
            assert(sum.x == 5.0);
            assert(sum.y == 7.0);
            assert(sum.z == 9.0);
        }   

        void test_plus_eqs()
        {
            Normal n1(1.0, 2.0, 3.0);
            Normal n2(4.0, 5.0, 6.0);
            n1+=n2;
            assert(n1.x == 5.0);
            assert(n1.y == 7.0);
            assert(n1.z == 9.0);
        }

        void test_minus()
        {
            Normal n1(4.0, 5.0, 6.0);
            Normal n2(1.0, 2.0, 3.0);
            Normal diff = n2-n1;
            assert(diff.x == -3.0);
            assert(diff.y == -3.0);
            assert(diff.z == -3.0);
        }

        void test_minus_eqs()
        {
            Normal n1(1.0, 2.0, 3.0);
            Normal n2(4.0, 5.0, 6.0);
            n2-=n1;
            assert(n2.x == 3.0);
            assert(n2.y == 3.0);
            assert(n2.z == 3.0);
        }

        void test_mult()
        {
            double a = 2.5;
            Normal n(2.0, 4.0, 6.0);
            Normal scale = n*a;
            assert(scale.x == 5.0);
            assert(scale.y == 10.0);
            assert(scale.z == 15.0); 
        }

        void test_mult_eqs()
        {
            double a = 2.0;
            Normal n(1.0, 2.0, 3.0);
            n*=a;
            assert(n.x == 2.0);
            assert(n.y == 4.0);
            assert(n.z == 6.0);
        }

        void test_div()
        {
            double a = 2.0;
            Normal n(4.0, 5.0, 6.0);
            Normal div = n/a;
            assert(div.x == 2.0);
            assert(div.y == 2.5);
            assert(div.z == 3.0);
        }

        void test_div_eqs()
        {
            double a = 3.0;
            Normal n(12.0, 15.0, 18.0);
            n/=a;
            assert(n.x == 4.0);
            assert(n.y == 5.0);
            assert(n.z == 6.0);
        }

        void test_len_sqrd()
        {
            Normal n(1.0, 2.0, 3.0);
            assert(n.length_squared() == 14.0);
        }

        void test_length()
        {
            Normal n(1.0, 2.0, 2.0);
            assert(n.length() == 3.0);
        }

        void test_abs()
        {
            Normal n(-1.2, 3.5, -0.8);
            Normal m = abs(n);
            assert(m.x == 1.2);
            assert(m.y == 3.5);
            assert(m.z == 0.8);
        }

        void test_normalize()
        {
            Normal n(4.0, 3.0, 0.0);
            const double epsilon = 0.001;
            assert(std::abs((normalize(n)).x - 0.8) < epsilon);
            assert(std::abs((normalize(n)).y - 0.6) < epsilon);
            assert(std::abs((normalize(n)).z - 0.0) < epsilon);
        }

        void test_dot()
        {
            Normal n(1.0, 2.0, 3.0);
            Vector3 v(4.0, 5.0, 6.0);
            double l = dot( n, v );
            assert(l == 32.0);
        }

        void test_mult2()
        {
            double s = 5.0;
            Normal n(1.0,  2.0, 3.0);
            assert((s*n).x == 5.0);
            assert((s*n).y == 10.0);
            assert((s*n).z == 15.0);
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
    RT::test_mult();
    RT::test_mult_eqs();
    RT::test_div();
    RT::test_div_eqs();
    RT::test_len_sqrd();
    RT::test_length();
    RT::test_abs();
    RT::test_normalize();
    RT::test_dot();
    RT::test_mult2();

    std::cout << "Normal class unit test successfully completed.\n";
    return 0;
}
