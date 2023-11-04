#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
-I/home/norman/code/ray_tracer/include/utility \
/home/norman/code/ray_tracer/src/utility/HitRecord.cpp \
/home/norman/code/ray_tracer/src/utility/RGBColor.cpp \
-I/home/norman/code/ray_tracer/include/light \
/home/norman/code/ray_tracer/src/light/Light.cpp \
/home/norman/code/ray_tracer/src/light/PointLight.cpp \
/home/norman/code/ray_tracer/test/light/Point_Light.test.cpp \
-o Point_Light_test
./Point_Light_test
