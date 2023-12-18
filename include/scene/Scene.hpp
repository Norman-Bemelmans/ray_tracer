// Scene class definition
// This is a bare-bones implementation, just enough to draw something
// to the screen.

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Light.hpp"
#include "Shape.hpp"

#include <memory>
#include <vector>

namespace RT {
class Film;
class Pinhole;
class HitRecord;

class Scene {
public:
    Scene() = default;

    // Initializes the scene and sets it up to render an image.
    void init();

    // Manages rendering process.
    void renderScene();
private:
    std::vector<std::unique_ptr<Light>> lightContainer;
    std::vector<std::unique_ptr<Shape>> shapeContainer;
    Film* pFilm;
    Pinhole* pCamera;
};
} // namespace RT

#endif

