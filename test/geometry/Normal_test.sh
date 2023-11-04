#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
/home/norman/code/ray_tracer/test/geometry/Normal.test.cpp \
-o Normal_test
./Normal_test
