// Point_Light (derived from Light) class declarations

#include "Point_Light.hpp"
#include "Light.hpp"
#include "RGB_Color.hpp"
#include "Point3.hpp"
#include "Hit_Record.hpp"

namespace RT {

    Point_Light::Point_Light() : Light(), loc(0.0, 0.0, 0.0) {}
    Point_Light::Point_Light(RGB_Color color_init, Point3 loc_init) : Light(color_init), loc(loc_init) {}

    Vector3 Point_Light::ptl_dir(const Hit_Record& hr)
    {
        return Vector3(loc - hr.hp);
    }
}
