// Shape (abstract) class implementation.

#include "Shape.hpp"
#include "Material.hpp"

namespace RT {
Shape::Shape(Material* mat) : material(mat) {}
Shape::~Shape() {}
} // namespace RT
