// Shape (abstract) class declarations.

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Ray.hpp"
#include "Material.hpp"

namespace RT {
    class Shape {
    protected:
        virtual hit(Ray r) = 0;
    private:
        Material* material;
    };
}

#endif
