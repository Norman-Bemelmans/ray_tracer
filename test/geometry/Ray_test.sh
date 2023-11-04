#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
/home/norman/code/ray_tracer/src/geometry/Ray.cpp \
/home/norman/code/ray_tracer/test/geometry/Ray.test.cpp \
-o Ray_test
./Ray_test
