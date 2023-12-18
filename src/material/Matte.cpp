// Matte (derived from Material) class implementation

#include "Matte.hpp"
#include "RGBColor.hpp"
#include "HitRecord.hpp"
#include "Vector3.hpp"
#include "Normal.hpp"
#include "Point3.hpp"

#include <algorithm>
#include <vector>
#include <iostream>

namespace RT {
Matte::Matte() : ka(RGBColor(1.0, 1.0, 1.0)), kd(RGBColor(0.5, 0.5, 0.5)) {}
Matte::Matte(RGBColor ka, RGBColor kd) : ka(ka), kd(kd) {}

RGBColor Matte::shade(const Point3& hitPoint, const Normal& normal, const Light* light) {
    Vector3 ptl = light->ptlDir(hitPoint);

    RGBColor rad { kd * std::max(static_cast<float>(0.0), (dot(normalize(normal), normalize(ptl)))) };
    return rad;
}
} // namespace RT
