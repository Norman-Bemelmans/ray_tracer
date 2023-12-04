// Global math utility function implementations.

#include "MathUtils.hpp"

namespace RT {
    std::pair<double, double> quadratic(double a, double b, double c) {
        double discriminant = b*b - 4*a*c;
        // If discriminant is less than zero then there are no real roots and we return infinity.
        if (discriminant < 0) {
            return std::pair<double, double>(infDouble,
                                             infDouble);
        }
        double denom = 2*a;
        double root1 = (-b - std::sqrt(discriminant)) / denom;
        double root2 = (-b + std::sqrt(discriminant)) / denom;

        return std::pair<double, double>(root1, root2);
    }
}
