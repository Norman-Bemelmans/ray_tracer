#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/test/geometry/Vector3.test.cpp \
-o Vector3_test
./Vector3_test
