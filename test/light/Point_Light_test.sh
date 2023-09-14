#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/src/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
-I/home/norman/code/ray_tracer/src/utility \
/home/norman/code/ray_tracer/src/utility/Hit_Record.cpp \
/home/norman/code/ray_tracer/src/utility/RGB_Color.cpp \
-I/home/norman/code/ray_tracer/src/light \
/home/norman/code/ray_tracer/src/light/Light.cpp \
/home/norman/code/ray_tracer/src/light/Point_Light.cpp \
/home/norman/code/ray_tracer/src/light/Point_Light.test.cpp \
-o Point_Light_test
./Point_Light_test
