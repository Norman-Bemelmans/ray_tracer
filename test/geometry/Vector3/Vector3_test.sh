#! /usr/bin/bash

sudo g++ -I/home/norman/code/ray_tracer/src/geometry /home/norman/code/ray_tracer/src/geometry/Vector3.cpp /home/norman/code/ray_tracer/src/geometry/Vector3.test.cpp -o Vector3_test
./Vector3_test
