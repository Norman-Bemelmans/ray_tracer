// Material (abstract class) declaration
// Each derived class must provide a shade() method which computes 
// the radiance at a given pixel.

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <vector>

#include "Light.hpp"
#include "RGB_Color.hpp"
//#include "Hit_Record.hpp"

namespace RT {

    class Hit_Record;

    class Material {
    protected:
        virtual RGB_Color shade(const Hit_Record& hr,  const std::vector<RT::Light>& lv) = 0;
        // max_to_one handles out-of-gamut colors. It divides all color channels by the value 
        // of the max channel so that the RGB_Color has no channel higher than one.
        RGB_Color max_to_one(const RGB_Color& col);
    };
}

#endif
