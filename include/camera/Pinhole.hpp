// Pinhole (derived camera class) declarations

#ifndef PINHOLE_HPP
#define PINHOLE_HPP

#include "Camera.hpp"
#include "Ray.hpp"

namespace RT {
class Pinhole : public Camera {
    friend void test_def_ctor();
    friend void test_ctor();
public:
    Pinhole();
    Pinhole(Point3 ep, Point3 vd, Vector3 up, float fl,
            int v, int h, float t, float b, float l, float r);

    Ray createRay(int u, int v) override;

    // vertical/horizontal resolution of image:
    const int vres;
    const int hres;
private:
    // top, bottom, left, right.
    float t, b, l, r;
};
} // namespace RT

#endif
