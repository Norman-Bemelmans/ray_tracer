// RGB_Color class unit test.

#include <cmath>
#include <cassert>
#include <iostream>

#include "RGB_Color.hpp"

namespace RT {

    void test_def_ctor()
    {
        RGB_Color test;
        assert(test.r == 0.0);
        assert(test.g == 0.0);
        assert(test.b == 0.0);
    }

    void test_ctor()
    {
        RGB_Color test(0.5, 0.5, 0.5);
        assert(test.r == 0.5);
        assert(test.g == 0.5);
        assert(test.b == 0.5);
    }

    void test_plus()
    {
        float epsilon = 0.00001;
        RGB_Color c1(0.1, 0.1, 0.1);
        RGB_Color c2(0.2, 0.2, 0.2);
        RGB_Color sum = c1+c2;
        assert(std::abs(sum.r - 0.3) < epsilon);
        assert(std::abs(sum.g - 0.3) < epsilon);
        assert(std::abs(sum.b - 0.3) < epsilon);
    }

    void test_plus_eqs()
    {
        float epsilon = 0.00001;
        RGB_Color c1(0.1, 0.2, 0.3);
        RGB_Color c2(0.1, 0.2, 0.3);
        c1+=c2;
        assert(std::abs(c1.r - 0.2) < epsilon);
        assert(std::abs(c1.g - 0.4) < epsilon);
        assert(std::abs(c1.b - 0.6) < epsilon);
    }

    void test_mult()
    {
        float epsilon = 0.00001;
        RGB_Color a(0.2, 0.2, 0.2);
        RGB_Color b(0.2, 0.3, 0.1);
        RGB_Color prod = a*b;
        assert(std::abs(prod.r - 0.04) < epsilon);
        assert(std::abs(prod.g - 0.06) < epsilon);
        assert(std::abs(prod.b - 0.02) < epsilon);
    }

    void test_mult_scalar()
    {
        float epsilon = 0.00001;
        float s = 2.0;
        RGB_Color c(0.2, 0.3, 0.4);
        assert(std::abs((s*c).r - 0.4) < epsilon);
        assert(std::abs((s*c).g - 0.6) < epsilon);
        assert(std::abs((s*c).b - 0.8) < epsilon);
    }

    void test_div()
    {
        float epsilon = 0.00001;
        float a = 2.0;
        RGB_Color c(0.4, 0.6, 0.8);
        RGB_Color div = c/a;
        assert(std::abs(div.r - 0.2) < epsilon);
        assert(std::abs(div.g - 0.3) < epsilon);
        assert(std::abs(div.b - 0.4) < epsilon);
    }

    void test_exponent()
    {
        float epsilon = 0.00001;
        float a = 2.0;
        RGB_Color c(0.2, 0.2, 0.2);
        RGB_Color exp = c.exp(a);
        assert(std::abs(exp.r - 0.04) < epsilon);
        assert(std::abs(exp.g - 0.04) < epsilon);
        assert(std::abs(exp.b - 0.04) < epsilon);
    }
}

int main()
{
    RT::test_def_ctor();
    RT::test_ctor();
    RT::test_plus();
    RT::test_plus_eqs();
    RT::test_mult();
    RT::test_mult_scalar();
    RT::test_div();
    RT::test_exponent();

    std::cout << "RGB_Color class unit test successfully completed.\n";
    return 0;
}