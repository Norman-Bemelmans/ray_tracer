// Camera class declarations.

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vector3.hpp"
#include "Point3.hpp"

namespace RT {

    class Camera {
    private:
        // eye-point is  the camera origin.
        Point3 eye_point;
        // view_dir is the direction the camera is looking.
        Vector3 view_dir;
        // up is a vector that points up relative to the camera.
        Vector3 up;

        // focal_length is the distance between the eye_point and
        // the image plane.
        float focal_length;

        // Coordinates for top, bottom, left, and right of image plane.
        float t, b, l, r;

        
    };
}
