// Matte (derived from Material) class implementation

#include <vector>
#include <iostream>

#include "Matte.hpp"
#include "RGB_Color.hpp"
#include "Hit_Record.hpp"

namespace RT{

    Matte::Matte() : ka(1.0), kd(1.0) , cd(0.5, 0.5, 0.5) {}
    Matte::Matte(float ka, float kd, RGB_Color cd) : ka(ka), kd(kd), cd(cd) {}

    // For now, I am ignoring global illumination and the directional aspect
    // of the shading calculation. These will need to wait for more classes 
    // in order to be implemented.
    RGB_Color Matte::shade(const Hit_Record& hr, const std::vector<Light*>& lv)
    {
        // return pixel radiance value:
        RGB_Color rad;
        for (auto i = 0; i < lv.size(); i++) {
            rad += kd * lv[i] -> color;
        }
        rad = Material::max_to_one(rad);
        return rad;
    }
}
