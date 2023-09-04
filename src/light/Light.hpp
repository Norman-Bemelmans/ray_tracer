// Light (abstract class) declarations:

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Vector3.hpp"
#include "RGB_Color"
#include "Hit_Record"

namespace RT {

    class Light {
    public::
        Light();
        virtual ~Light();

        // point-to-light direction:
        virtual Vector3 ptl_dir(const Hit_Record hr) = 0;
    private:
        RGB_Color color;
    };
}

#endif
