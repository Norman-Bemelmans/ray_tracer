// Hit_Record class implementation

#include "HitRecord.hpp"
#include "Normal.hpp"
#include "Point3.hpp"

namespace RT {

    HitRecord::HitRecord() : hp(0.0, 0.0, 0.0), sn(0.0, 0.0, 0.0), mat(nullptr) {}
}