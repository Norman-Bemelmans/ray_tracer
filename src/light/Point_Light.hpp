// Point_Light (derived from Light) declarations

#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include "Light.hpp"
#include "RGB_Color.hpp"
#include "Point3.hpp"
#include "Vector3.hpp"
#include "Hit_Record.hpp"

namespace RT {

    class Point_Light : public Light {
        friend void test_def_ctor();
        friend void test_ctor();
    public:
        Point_Light();
        Point_Light(RGB_Color color_init, Point3 loc_init);

        Vector3 ptl_dir(const Hit_Record& hr);
    private:
        // Location of point light.
        Point3 loc;
    };
}

#endif
