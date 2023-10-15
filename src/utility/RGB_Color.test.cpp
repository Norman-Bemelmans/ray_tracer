// RGBColor class unit test.

#include <cmath>
#include <cassert>
#include <iostream>

#include "RGBColor.hpp"

namespace RT {

    void test_def_ctor()
    {
        RGBColor test;
        assert(test.r == 0.0);
        assert(test.g == 0.0);
        assert(test.b == 0.0);
    }

    void test_ctor()
    {
        RGBColor test(0.5, 0.5, 0.5);
        assert(test.r == 0.5);
        assert(test.g == 0.5);
        assert(test.b == 0.5);
    }

    void test_plus()
    {
        float epsilon = 0.00001;
        RGBColor c1(0.1, 0.1, 0.1);
        RGBColor c2(0.2, 0.2, 0.2);
        RGBColor sum = c1+c2;
        assert(std::abs(sum.r - 0.3) < epsilon);
        assert(std::abs(sum.g - 0.3) < epsilon);
        assert(std::abs(sum.b - 0.3) < epsilon);
    }

    void test_plus_eqs()
    {
        float epsilon = 0.00001;
        RGBColor c1(0.1, 0.2, 0.3);
        RGBColor c2(0.1, 0.2, 0.3);
        c1+=c2;
        assert(std::abs(c1.r - 0.2) < epsilon);
        assert(std::abs(c1.g - 0.4) < epsilon);
        assert(std::abs(c1.b - 0.6) < epsilon);
    }

    void test_mult()
    {
        float epsilon = 0.00001;
        RGBColor a(0.2, 0.2, 0.2);
        RGBColor b(0.2, 0.3, 0.1);
        RGBColor prod = a*b;
        assert(std::abs(prod.r - 0.04) < epsilon);
        assert(std::abs(prod.g - 0.06) < epsilon);
        assert(std::abs(prod.b - 0.02) < epsilon);
    }

    void test_mult_scalar()
    {
        float epsilon = 0.00001;
        float s = 2.0;
        RGBColor c(0.2, 0.3, 0.4);
        assert(std::abs((s*c).r - 0.4) < epsilon);
        assert(std::abs((s*c).g - 0.6) < epsilon);
        assert(std::abs((s*c).b - 0.8) < epsilon);
    }

    void test_div()
    {
        float epsilon = 0.00001;
        float a = 2.0;
        RGBColor c(0.4, 0.6, 0.8);
        RGBColor div = c/a;
        assert(std::abs(div.r - 0.2) < epsilon);
        assert(std::abs(div.g - 0.3) < epsilon);
        assert(std::abs(div.b - 0.4) < epsilon);
    }

    void test_exponent()
    {
        float epsilon = 0.00001;
        float a = 2.0;
        RGBColor c(0.2, 0.2, 0.2);
        RGBColor exp = c.exp(a);
        assert(std::abs(exp.r - 0.04) < epsilon);
        assert(std::abs(exp.g - 0.04) < epsilon);
        assert(std::abs(exp.b - 0.04) < epsilon);
    }

    void test_max_to_one()
    {
        const float epsilon = 0.00001;
        RGBColor col(1.2, 1.3, 1.4);
        RGBColor colcor = maxToOne(col);
        assert(std::abs(colcor.r - 0.857143) < epsilon);
        assert(std::abs(colcor.g - 0.928571) < epsilon);
        assert(std::abs(colcor.b - 1.000000) < epsilon);
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
    RT::test_max_to_one();

    std::cout << "RGBColor class unit test successfully completed.\n";
    return 0;
}