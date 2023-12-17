// Hit_Record class declarations
// Hit_Record allows for information transfer between the geometry and shading 
// subsystems of the tracer. 

#ifndef HITRECORD_HPP
#define HITRECORD_HPP

#include "Point3.hpp"
#include "Normal.hpp"
#include "RGBColor.hpp"

namespace RT {
class Material;

class HitRecord {
public:
    HitRecord();
    
    Point3 hp;
    Normal sn;
    RGBColor col;
    Material* mat;
};
} // namespace RT

#endif
