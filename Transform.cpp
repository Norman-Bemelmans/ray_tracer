//Transform class implementation

#iclude "Transform.h"

Transform::Transform() : entry[0][0](1), entry[0][1](0), entry[0][2](0),
                         entry[1][0](0), entry[1][1](1), entry[1][2](0),
                         entry[2][0](0), entry[2][1](0), entry[2][2](1),
                         inverse[0][0](1), inverse[0][1](0), inverse[0][2](0),
                         inverse[1][0](0), inverse[1][1](1), inverse[1][2](0),
                         inverse[2][0](0), inverse[2][1](0), inverse[2][2](1),
                         det(1), InvDet(1) {}

Transform::Transform(double m00, double m01, double m02,
                     double m10, double m11, double m12,
                     double m20, double m21, double m22) 
{
                        entry[0][0] = m00; entry[0][1] = m01; entry[0][2] = m02;
                        entry[1][0] = m10; entry[1][1] = m11; entry[1][2] = m12;
                        entry[2][0] = m20; entry[2][1] = m21; entry[2][2] = m22;
                        det = m00*(m11*m22 - m21*m12) -
                              m01*(m10*m22 - m20*m12) +
                              m02*(m10*m21 - m20*m11);
                        invDet = 1 / det;
                        inverse[0][0] = invDet*(m11*m22 - m12*m21);
                        inverse[0][1] = invDet*(m02*m21 - m01*m22);
                        inverse[0][2] = invDet*(m01*m12 - m02*m11);
                        inverse[1][0] = invDet*(m12*m20 - m10*m22);
                        inverse[1][1] = invDet*(m00*m22 - m02*m20);
                        inverse[1][2] = invDet*(m02*m10 - m00*m12);
                        inverse[2][0] = invDet*(m10*m21 - m11*m20);
                        inverse[2][1] = invDet*(m01*m20 - m00*m21);
                        inverse[2][2] = invDet*(m00*m11 - m01*m10);
}

// The multiplication methods are implemented as left-multiplication;
// that is, for a transform T, T*v is the result of the linear transformation
// associated with T applied to the vector v. Likewise for matrix mutiplication
// (the object pointed to by "this" is left multiplied by the supplied parameter.)
Vector3 Transform::operator*(const Vector3& vec) const
{
    return Vector3(m00*vec.x + m01*vec.y + m02*vec.z,
                   m10*vec.x + m11*vec.y + m12*vec.z,
                   m20*vec.x + m21*vec.y + m22*vec.z);
}

Transform Transform::operator*(const Transform& t) const
{
    return Transform(m00*t.m00 + m01*t.m10 + m02*t.m20,
                     m00*t.m01 + m01*t.m11 + m02*t.m21,
                     m00*t.m02 + m01*t.m12 + m02*t.m22,
                     m10*t.m00 + m11*t.m10 + m12*t.m20,
                     m10*t.m01 + m11*t.m11 + m12*t.m21,
                     m10*t.m02 + m11*t.m12 + m12*t.m22,
                     m20*t.m00 + m21*t.m10 + m22*t.m20,
                     m20*t.m01 + m21*t.m11 + m22*t.m21,
                     m20*t.m02 + m21*t.m12 + m22*t.m22);
}
