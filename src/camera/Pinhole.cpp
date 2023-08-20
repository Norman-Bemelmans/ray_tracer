// Pinhole (Camera derived class) implementations

#include "Pinhole.hpp"
#include "Point3.hpp"
#include "Vector3.hpp"
#include "Ray.hpp"

namespace RT {

    Pinhole::Pinhole() : vres(300), hres(400), t(-150.0), b(150.0),
                         l(-200.0), r(200.0) {}
    Pinhole::Pinhole(Point3 ep, Point3 vd, Vector3 up, float fl,
                     int v, int h, float t, float b, float l, float r) :
                     Camera(ep, vd, up, fl), vres(v), hres(h), t(t), b(b),
                     l(l), r(r) {}

    Ray Pinhole::Create_Ray(float u, float v)
    {
        return Ray(Point3(0.0, 0.0, 0.0), Vector3(l + (r - l)*(u + 0.5)/hres, t + (b -t)*(v + 0.5)/vres, foc_len));
    }
}