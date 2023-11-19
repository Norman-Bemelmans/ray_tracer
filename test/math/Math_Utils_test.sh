#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/math \
/home/norman/code/ray_tracer/src/math/MathUtils.cpp \
/home/norman/code/ray_tracer/test/math/MathUtils.test.cpp \
-o MathUtils_test 
./MathUtils_test
