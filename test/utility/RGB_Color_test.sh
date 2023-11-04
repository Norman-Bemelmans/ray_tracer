#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/utility \
/home/norman/code/ray_tracer/src/utility/RGBColor.cpp \
/home/norman/code/ray_tracer/test/utility/RGB_Color.test.cpp \
-o RGB_Color_test
./RGB_Color_test
