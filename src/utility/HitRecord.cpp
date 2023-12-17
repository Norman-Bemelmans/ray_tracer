// Hit_Record class implementation

#include "HitRecord.hpp"
#include "Normal.hpp"
#include "Point3.hpp"
#include "RGBColor.hpp"

namespace RT {
HitRecord::HitRecord() : hp(0.0, 0.0, 0.0), sn(0.0, 0.0, 0.0), col(0.0, 0.0, 0.0), mat(nullptr) {}
} // namespace RT