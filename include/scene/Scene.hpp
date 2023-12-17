// Scene class definition
// This is a bare-bones implementation, just enough to draw something
// to the screen.

#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <vector>

namespace RT {
class Light;
class Shape;
class Film;
class Camera;

class Scene {
public:
    Scene() = default;
    // Initializes the scene and sets it up to render an image.
    void init();
private:
    std::vector<std::unique_ptr<Light>> lightContainer;
    std::vector<std::unique_ptr<Shape>> shapeContainer;
    Film* pFilm;
    Camera* pCamera;
};
} // namespace RT

#endif

