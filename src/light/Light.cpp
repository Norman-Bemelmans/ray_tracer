// Light (abstract class) declarations

#include "Light.hpp"
#include "RGBColor.hpp"

namespace RT { 
Light::Light() : color(1.0, 1.0, 1.0) {}
Light::Light(const RGBColor& color) : color(color) {}
Light::~Light() {}
} // namespace RT