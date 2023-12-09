// Global math utility methods that (which?) any class can use.

#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

#include <utility>
#include <cmath>
#include <limits>

namespace RT {
// Max size of a double for this system.
const double maxDouble = std::numeric_limits<double>::max();

// Double which should compare to greater than any other double value.
const double infDouble = std::numeric_limits<double>::infinity();

// Quadratic solver. Returns value of two roots if they are real,
// returns std::pair<infDouble, infDouble> otherwise.
std::pair<double, double> quadratic(double a, double b, double c);
} // namespace RT

#endif
