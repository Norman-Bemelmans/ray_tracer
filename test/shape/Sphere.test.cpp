// Sphere class unit tests

#include "Sphere.hpp"
#include "Point3.hpp"
#include "Vector3.hpp"
#include "Ray.hpp"
#include "MathUtils.hpp"
#include "HitRecord.hpp"
#include "Material.hpp"
#include "Matte.hpp"
#include "Transform.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

namespace RT {
void test_ctor() {
    Point3 p(1.0, 2.0, 4.0);
    Material* pmat = new Matte;
    Sphere s(p, 1.0, pmat);

    assert(s.center.x == 1.0);
    assert(s.center.y == 2.0);
    assert(s.center.z == 4.0);
    assert(s.radius == 1.0);
}

void test_hit_false() {
    Point3 p(0.0, 0.0, 0.0);
    Material* pmat = new Matte;
    Sphere s(p, 1.0, pmat);

    Point3 o(1.0, 2.0, 4.0);
    Vector3 d(-2.3, 1.7, 2.2);
    Ray r(o, d);
    HitRecord* phr = new HitRecord;

    assert(s.hit(r, phr) == false);
}

void test_hit_true() {
    Point3 p(0.0, 0.0, 5.0);
    Material* pmat = new Matte;
    Sphere s(p, 1.0, pmat);

    Point3 o(0.0, 0.0, 0.0);
    Vector3 d(0.0, 0.0, 1.0);
    Ray r(o, d);
    HitRecord* phr = new HitRecord;

    assert(s.hit(r, phr) == true);
    assert((phr->hp).x == 0.0);
    assert((phr->hp).y == 0.0);
    assert((phr->hp).z == 4.0);
    assert((phr->sn).x == 0.0);
    assert((phr->sn).y == 0.0);
    assert((phr->sn).z == -1.0);
}
} // namespace RT

int main() {
    RT::test_ctor();
    RT::test_hit_false();
    RT::test_hit_true();

    std::cout << "Sphere class unit test successfully completed.\n";
    return 0;
}
