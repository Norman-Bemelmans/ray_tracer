// Shape (abstract) class declarations.

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Ray.hpp"
#include "Material.hpp"
#include "HitRecord.hpp"

namespace RT {
    class Shape {
    public:
        virtual ~Shape() = 0;
    protected:
        Shape();
        virtual bool hit(Ray r, HitRecord* hitRecord) = 0;
    private:
        Material* material;
    };
}

#endif
