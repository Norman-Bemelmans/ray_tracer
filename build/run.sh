#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/camera \
/home/norman/code/ray_tracer/src/camera/Camera.cpp \
/home/norman/code/ray_tracer/src/camera/Pinhole.cpp \
-I/home/norman/code/ray_tracer/include/film \
/home/norman/code/ray_tracer/src/film/Film.cpp \
-I/home/norman/code/ray_tracer/include/geometry \
/home/norman/code/ray_tracer/src/geometry/Matrix.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
/home/norman/code/ray_tracer/src/geometry/Ray.cpp \
/home/norman/code/ray_tracer/src/geometry/Transform.cpp \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
-I/home/norman/code/ray_tracer/include/light \
/home/norman/code/ray_tracer/src/light/Light.cpp \
/home/norman/code/ray_tracer/src/light/PointLight.cpp \
-I/home/norman/code/ray_tracer/include/material \
/home/norman/code/ray_tracer/src/material/Material.cpp \
/home/norman/code/ray_tracer/src/material/Matte.cpp \
-I/home/norman/code/ray_tracer/include/math \
/home/norman/code/ray_tracer/src/math/MathUtils.cpp \
-I/home/norman/code/ray_tracer/include/scene \
/home/norman/code/ray_tracer/src/scene/Scene.cpp \
-I/home/norman/code/ray_tracer/include/shape \
/home/norman/code/ray_tracer/src/shape/Shape.cpp \
/home/norman/code/ray_tracer/src/shape/Sphere.cpp \
-I/home/norman/code/ray_tracer/include/utility \
/home/norman/code/ray_tracer/src/utility/HitRecord.cpp \
/home/norman/code/ray_tracer/src/utility/RGBColor.cpp \
-I/home/norman/code/ray_tracer/build \
/home/norman/code/ray_tracer/build/main.cpp \
-o render
./render
