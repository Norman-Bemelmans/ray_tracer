// Global math utility methods that (which?) any class can use.

#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

#include <utility>
#include <cmath>
#include <limits>

namespace RT {
    const double maxDouble = std::numeric_limits<double>::max();
    const double infDouble = std::numeric_limits<double>::infinity();
    std::pair<double, double> quadratic(double a, double b, double c);
}

#endif
