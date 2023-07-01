//Transform header file

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector3.h"

class Transform {
private:
// Transforms are implemented with doubles rather than floats.
// This may need to change if performance suffers.
    const double entry[3][3];
    const double det;
    const double invDet;
    const double inverse[3][3];

public:
    Transform();
    Transform(double m00, double m01, double m02,
              double m10, double m11, double m12,
              double m20, double m21, double m22);
    Vector3 operator*(const Vector3& vec) const;
    Transform operator*(const Transform& t) const;
};

#endif
