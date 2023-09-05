// Hit_Record class declarations
// Hit_Record allows for information transfer between the geometry and shading 
// subsystems of the tracer. 

#ifndef HIT_RECORD_HPP
#define HIT_RECORD_HPP

#include "Normal.hpp"
#include "Point3.hpp"
//#include "Material.hpp"

namespace RT {

    class Material;

    class Hit_Record {
    public:
        Hit_Record();
        
        Point3 hp;
        Normal sn;
        Material* mat;
    };
}

#endif
