// Point_Light (derived from Light) declarations

#ifndef POINT_LIGHT
#define POINT_LIGHT

#include "Light.hpp"
#include "RGB_Color.hpp"
#include "Point3.hpp"
#include "Vector3.hpp"
#include "Hit_Record.hpp"

namespace RT {

    class Point_Light : public Light {
    public:
        Point_Light();
        Point_Light(Point3 loc_init, RGB_Color color_init);

        Vector3 ptl_dir(const Hit_Record& hr);
    private:
        // Location of point light.
        Point3 loc;
    };
}

#endif
