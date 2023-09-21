#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/src/utility \
/home/norman/code/ray_tracer/src/utility/RGB_Color.cpp \
/home/norman/code/ray_tracer/src/utility/Hit_Record.cpp \
-I/home/norman/code/ray_tracer/src/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
-I/home/norman/code/ray_tracer/src/light \
/home/norman/code/ray_tracer/src/light/Light.cpp \
/home/norman/code/ray_tracer/src/light/Point_Light.cpp \
-I/home/norman/code/ray_tracer/src/material \
/home/norman/code/ray_tracer/src/material/Material.cpp \
/home/norman/code/ray_tracer/src/material/Matte.cpp \
/home/norman/code/ray_tracer/src/material/Matte.test.cpp \
-o Matte_test
./Matte_test
