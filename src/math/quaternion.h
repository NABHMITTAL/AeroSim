#include "vector3.h"
#pragma once

 namespace aerosim{
  struct Quaternion{
    float w;
    float x;
    float y;
    float z;

    Quaternion operator*(const Quaternion& other) const;
    Quaternion normalized() const;
    float magnitude() const;
    Vector3 rotate(const Vector3& vector) const;
    Quaternion conjugate() const;
  };
 }