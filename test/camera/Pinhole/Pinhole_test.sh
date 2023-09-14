#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/src/geometry \
/home/norman/code/ray_tracer/src/geometry/Vector3.cpp \
/home/norman/code/ray_tracer/src/geometry/Point3.cpp \
/home/norman/code/ray_tracer/src/geometry/Normal.cpp \
/home/norman/code/ray_tracer/src/geometry/Matrix.cpp \
/home/norman/code/ray_tracer/src/geometry/Transform.cpp \
/home/norman/code/ray_tracer/src/geometry/Ray.cpp \
-I/home/norman/code/ray_tracer/src/camera \
/home/norman/code/ray_tracer/src/camera/Camera.cpp \
/home/norman/code/ray_tracer/src/camera/Pinhole.cpp \
/home/norman/code/ray_tracer/src/camera/Pinhole.test.cpp \
-o Pinhole_test
./Pinhole_test
