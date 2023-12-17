#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/include/geometry \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
-I/home/norman/code/ray_tracer/include/utility \
/home/norman/code/ray_tracer/src/utility/HitRecord.cpp \
/home/norman/code/ray_tracer/src/utility/RGBColor.cpp \
/home/norman/code/ray_tracer/test/utility/Hit_Record.test.cpp \
-o Hit_Record_test
./Hit_Record_test
