// Light (abstract class) declarations:

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Vector3.hpp"
#include "RGB_Color.hpp"
#include "Hit_Record.hpp"

namespace RT {

    class Light {
    public:
        Light();
        virtual ~Light();

        // point-to-light direction:
        virtual Vector3 ptl_dir(const Hit_Record& hr) = 0;
    protected:
        RGB_Color color;
    };
}

#endif
