#pragma once
#include "matrix3.h"

 namespace aerosim{
  struct EulerAngles{
    float yaw;
    float pitch;
    float roll;

    Matrix3 toRotationMatrix() const;

  };
 }