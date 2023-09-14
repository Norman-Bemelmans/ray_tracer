#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/src/utility \
/home/norman/code/ray_tracer/src/utility/RGB_Color.cpp \
/home/norman/code/ray_tracer/src/utility/RGB_Color.test.cpp \
-o RGB_Color_test
./RGB_Color_test
