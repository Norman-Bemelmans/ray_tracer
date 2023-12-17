#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/utility \
/home/norman/code/ray_tracer/src/utility/RGBColor.cpp \
-I/home/norman/code/ray_tracer/include/film \
/home/norman/code/ray_tracer/src/film/Film.cpp \
/home/norman/code/ray_tracer/test/film/Film.test.cpp \
-o Film_test
./Film_test
