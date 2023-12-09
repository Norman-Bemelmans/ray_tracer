// Camera class declarations.

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vector3.hpp"
#include "Point3.hpp"
#include "Transform.hpp"
#include "Ray.hpp"

namespace RT {
class Camera {
    friend void test_def_ctor();
    friend void test_ctor();

public:
    Camera();
    Camera(Point3 ep, Point3 vd, Vector3 up, float fl);

    virtual ~Camera();
    virtual Ray createRay(float u, float v) = 0;

protected:
    // eye-point is  the camera origin.
    Point3 ep;
    // view_dir is a point the camera is looking at.
    Point3 vd;
    // up is a vector that points up relative to the camera.
    Vector3 up;

    // foc_len is the focal length: the distance between the eye_point and
    // the image plane.
    float focLen;

    // camera-to-world transform.
    Transform c2w;
};
} // namespace RT

#endif
