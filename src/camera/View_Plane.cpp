// View_Plane class implementation

#include "View_Plane.hpp"

namespace RT {

    View_Plane::View_Plane() : vres(300), hres(400),
                               t(-150.0), b(150.0),
                               l(-200.0), r(200.0) {}

    View_Plane::View_Plane(int v, int h, float t, float b, float l, float r)
        : vres(v), hres(h), t(t), b(b), l(l), r(r) {}
}
