// Matte (derived from Material) class unit test

#include "Matte.hpp"
#include "Material.hpp"
#include "RGBColor.hpp"
#include "HitRecord.hpp"
#include "Light.hpp"
#include "PointLight.hpp"
#include "Point3.hpp"

#include <vector>
#include <cassert>
#include <iostream>

namespace RT {
void test_def_ctor() {
    Matte test;
    assert(test.ka.r == 1.0);
    assert(test.ka.g == 1.0);
    assert(test.ka.b == 1.0);

    assert(test.kd.r == 0.5);
    assert(test.kd.g == 0.5);
    assert(test.kd.b == 0.5);
}

void test_ctor() {
    const float epsilon = 0.00001;
    Matte test(RGBColor(0.1, 0.2, 0.3), RGBColor(0.5, 0.6, 0.7));
    assert(std::abs(test.ka.r - 0.1) < epsilon);
    assert(std::abs(test.ka.g - 0.2) < epsilon);
    assert(std::abs(test.ka.b - 0.3) < epsilon);

    assert(std::abs(test.kd.r - 0.5) < epsilon);
    assert(std::abs(test.kd.g - 0.6) < epsilon);
    assert(std::abs(test.kd.b - 0.7) < epsilon);
}

void test_shade() {
    const float epsilon = 0.00001;
    HitRecord hitrec;
    hitrec.sn = Normal(0.0, -1.0, 0.0);

    PointLight light(RGBColor(), Point3(0.0, -1.0, 0.0));
    Matte test;

    assert(std::abs(test.shade(hitrec, light).r - 0.5) < epsilon);
    assert(std::abs(test.shade(hitrec, light).g - 0.5) < epsilon);
    assert(std::abs(test.shade(hitrec, light).b - 0.5) < epsilon);
}
} // namespace RT

int main() {
    RT::test_def_ctor();
    RT::test_ctor();
    RT::test_shade();

    std::cout << "Matte class unit test successfully completed.\n";
    return 0;
}
