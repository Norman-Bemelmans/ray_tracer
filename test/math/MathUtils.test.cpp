// Math utility methods tests.

#include "MathUtils.hpp"

#include <cmath>
#include <cassert>
#include <iostream>
#include <limits>

namespace RT {
void test_quadratic() {
    float epsilon = 0.00001;

    double a = 2.1;
    double b = 3.1;
    double c = 4.1;

    assert(std::abs(quadratic(a, b, c).first) - 
                    maxDouble > epsilon);
    assert(std::abs(quadratic(a, b, c).second) - 
                    maxDouble > epsilon);

    double x = 1.0;
    double y = 5.0;
    double z = 2.0;

    assert(std::abs(quadratic(x, y, z).first + 4.56155)  < epsilon);
    assert(std::abs(quadratic(x, y, z).second + 0.43844) < epsilon);
}
} // namespace RT

int main() {
    RT::test_quadratic();
    std::cout << "Math Utils unit test successfully completed.\n";
    return 0;
}

