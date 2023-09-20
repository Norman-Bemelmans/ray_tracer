// Light (abstract class) declarations:

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Vector3.hpp"
#include "RGB_Color.hpp"
#include "Hit_Record.hpp"

namespace RT {

    class Light {
        friend void test_def_ctor();
        friend void test_ctor();
    public:
        Light();
        Light(const RGB_Color& color);
        RGB_Color color;
        virtual ~Light();

        // point-to-light direction:
        virtual Vector3 ptl_dir(const Hit_Record& hr) = 0;
    };
}

#endif
