// Material (abstract class) declaration
// Each derived class must provide a shade() method which computes 
// the radiance at a given pixel.

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <vector>

#include "Light.hpp"
#include "RGB_Color.hpp"
#include "Hit_Record.hpp"

namespace RT {

    class Hit_Record;

    class Material {
    protected:
        virtual RGB_Color shade(const Hit_Record& hr,  const std::vector<RT::Light>& lv) = 0;
    };
}

#endif
