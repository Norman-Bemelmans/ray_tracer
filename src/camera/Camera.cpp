// Camera class implementation

#include "Camera.hpp"
#include "Point3.hpp"
#include "Vector3.hpp"
#include "Transform.hpp"

namespace RT {

    Camera::Camera() : ep(0.0, 0.0, 0.0), vd(0.0, 0.0, 1.0), up(0.0, -1.0, 0.0), foc_len(1.0),
                       c2w(1.0, 0.0, 0.0, 0.0,
                           0.0, 1.0, 0.0, 0.0,
                           0.0, 0.0, 1.0, 0.0,
                           0.0, 0.0, 0.0, 1.0) {}

    Camera::Camera(Point3 ep, Point3 vd, Vector3 up, float fl) : ep(ep), vd(vd), up(up), foc_len(fl)
    {
        c2w = look_at(ep, vd, up);
    }

    Camera::~Camera() {}
}