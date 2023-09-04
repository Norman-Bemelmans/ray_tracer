// Point_Light (derived from Light) declarations

#ifndef POINT_LIGHT
#define POINT_LIGHT

#include "Light.hpp"
#include "RGB_Color"
#include "Point3"
#include "Vector3"
#include "Hit_Record"

namespace RT {

    class Point_Light : public Light {
    public:
        Point_Light();
        Point_Light(Point3 pt, RGB_Color color);

        Vector3 ptl_dir(const Hit_Record& hr);
    private:
        // Location of point light.
        Point3 loc;
    };
}

#endif
