#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/src/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
/home/norman/code/ray_tracer/src/geometry/Ray.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
/home/norman/code/ray_tracer/src/geometry/Matrix.cpp \
/home/norman/code/ray_tracer/src/geometry/Transform.cpp \
/home/norman/code/ray_tracer/src/geometry/Transform.test.cpp \
-o Transform_test
./Transform_test
