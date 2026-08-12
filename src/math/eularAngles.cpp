#include "eularAngles.h"

namespace aerosim{

  Matrix3 EulerAngles::toRotationMatrix() const {
    Matrix3 yawMatrix = Matrix3::RotateZ(yaw);
    Matrix3 pitchMatrix = Matrix3::RotateY(pitch);
    Matrix3 rollMatrix = Matrix3::RotateX(roll);

    return yawMatrix * pitchMatrix * rollMatrix;
}
}