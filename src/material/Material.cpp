// Material (abstract class) implementation
// Empty for now.

#include <algorithm>

#include "Material.hpp"

namespace RT {

    RGB_Color Material::max_to_one(const RGB_Color& col)
    {
        float max = std::max({col.r, col.g, col.b});
        return RGB_Color(col.r / max, col.g / max, col.b / max);
    }
}