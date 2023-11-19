// Matte (derived from Material) class implementation

#include <vector>
#include <iostream>

#include "Matte.hpp"
#include "RGBColor.hpp"
#include "HitRecord.hpp"

namespace RT{
    Matte::Matte() : ka(1.0), kd(1.0) , cd(0.5, 0.5, 0.5) {}
    Matte::Matte(float ka, float kd, RGBColor cd) : ka(ka), kd(kd), cd(cd) {}

    // For now, I am ignoring global illumination and the directional aspect
    // of the shading calculation. These will need to wait for more classes 
    // in order to be implemented.
    RGBColor Matte::shade(const HitRecord& hr, const std::vector<Light*>& lv)
    {
        // return pixel radiance value:
        RGBColor rad;
        for (auto i = 0; i < lv.size(); i++) {
            rad += kd * lv[i] -> color;
        }
        rad = maxToOne(rad);
        return rad;
    }
}
