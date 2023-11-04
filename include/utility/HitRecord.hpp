// Hit_Record class declarations
// Hit_Record allows for information transfer between the geometry and shading 
// subsystems of the tracer. 

#ifndef HITRECORD_HPP
#define HITRECORD_HPP

#include "Normal.hpp"
#include "Point3.hpp"

namespace RT {

    class Material;

    class HitRecord {
    public:
        HitRecord ();
        
        Point3 hp;
        Normal sn;
        Material* mat;
    };
}

#endif
