// Hit_Record class declarations
// Hit_Record allows for information transfer between the geometry and shading 
// subsystems of the tracer. 

#ifndef HIT_RECORD_CPP
#define HIT_RECORD_CPP

#include <memory>

#include "Normal.hpp"
#include "Point3.hpp"
#include "Material.hpp"

namespace RT {

    class Hit_Record {
    public:
        Hit_Record();
    private:
        Point3 hp;
        Normal sn;
        std::unique_ptr<Material> mat;
    }
}