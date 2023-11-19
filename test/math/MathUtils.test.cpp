// Math utility methods tests.

#include <cmath>
#include <cassert>
#include <iostream>

#include "MathUtils.hpp"

namespace RT {
    void test_quadratic() {
        float epsilon = 0.00001;

        double a = 2.1;
        double b = 3.1;
        double c = 4.1;

        assert(std::abs(quadratic(a, b, c).first) - 0.0 < epsilon);
        assert(std::abs(quadratic(a, b, c).second) - 0.0  < epsilon);

        double x = 1.0;
        double y = 5.0;
        double z = 2.0;

        assert(std::abs(quadratic(x, y, z).first + 4.56155)  < epsilon);
        assert(std::abs(quadratic(x, y, z).second + 0.43844) < epsilon);
    }
}

int main() {
    RT::test_quadratic();
    std::cout << "Math Utils unit test successfully completed.\n";
    return 0;
}

