// Point_Light (derived from Light) class declarations

#include "Point_Light.hpp"
#include "Light.hpp"
#include "RGB_Color"
#include "Point3"
#include "Hit_Record"

namespace RT {

    Point_Light::Point_Light() : Light(), loc(0.0, 0.0, 0.0) {}
    Point_Light::Point_Light(RGB_Color color, Point3 loc) : color(color), loc(loc) {}

    Vector3 Point_Light::ptl_dir(const Hit_Record& hr)
    {
        return Vector3(loc-hr.hp);
    }
}
