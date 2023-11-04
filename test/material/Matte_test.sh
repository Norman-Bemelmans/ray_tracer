#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/utility \
/home/norman/code/ray_tracer/src/utility/RGBColor.cpp \
/home/norman/code/ray_tracer/src/utility/HitRecord.cpp \
-I/home/norman/code/ray_tracer/include/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
-I/home/norman/code/ray_tracer/include/light \
/home/norman/code/ray_tracer/src/light/Light.cpp \
/home/norman/code/ray_tracer/src/light/PointLight.cpp \
-I/home/norman/code/ray_tracer/include/material \
/home/norman/code/ray_tracer/src/material/Material.cpp \
/home/norman/code/ray_tracer/src/material/Matte.cpp \
/home/norman/code/ray_tracer/test/material/Matte.test.cpp \
-o Matte_test
./Matte_test
