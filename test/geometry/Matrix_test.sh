#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/geometry \
/home/norman/code/ray_tracer/src/geometry/Matrix.cpp \
/home/norman/code/ray_tracer/test/geometry/Matrix.test.cpp \
-o Matrix_test
./Matrix_test
