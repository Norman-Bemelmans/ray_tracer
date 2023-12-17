// Film class unit tests

#include "Film.hpp"
#include "RGBColor.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

namespace RT {
void film_test() {
    Film f;
    RGBColor col1(0.2, 0.1, 0.3);
    RGBColor col2(0.5, 0.5, 0.5);
    f.addToBitmap(col1);
    f.addToBitmap(col2);

    double epsilon = 0.00001;

    assert(std::abs(f.bitmap[0].r - 0.2) < epsilon);
    assert(std::abs(f.bitmap[0].g - 0.1) < epsilon);
    assert(std::abs(f.bitmap[0].b - 0.3) < epsilon);
    assert(std::abs(f.bitmap[1].r - 0.5) < epsilon);
    assert(std::abs(f.bitmap[1].g - 0.5) < epsilon);
    assert(std::abs(f.bitmap[1].b - 0.5) < epsilon);
}
} // namespacce RT

int main() {
    RT::film_test();
    std::cout << "Film class unit test successfully completed.\n";
    return 0;
}
