// Pinhole (derived camera class) declarations

#ifndef PINHOLE_HPP
#define PINHOLE_HPP

#include "Camera.hpp"
#include "Ray.hpp"

namespace RT {

    class Pinhole : public Camera {
        friend void test_def_ctor();
        friend void test_ctor();
    private:
        // vertical/horizontal resolution of image:
        int vres;
        int hres;
        // top, bottom, left, right.
        float t, b, l, r;
    public:
        Pinhole();
        Pinhole(Point3 ep, Point3 vd, Vector3 up, float fl,
                int v, int h, float t, float b, float l, float r);

        Ray Create_Ray(float u, float v);
    };
}

#endif
