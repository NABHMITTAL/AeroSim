#include "vector3.h"
#include "quaternion.h"
#include <cmath>

namespace aerosim{
    Quaternion Quaternion::operator*(const Quaternion& other) const{
      Vector3 v1{x, y, z};
      Vector3 v2{other.x, other.y, other.z};

      float newW = w * other.w - v1.dot(v2);

      Vector3 newV =
        v2 * w +
        v1 * other.w +
        v1.cross(v2);

      return {
        newW,
        newV.x,
        newV.y,
        newV.z
      };
    }

  float Quaternion::magnitude() const {
    return std::sqrt(w*w + x*x + y*y + z*z);
  }

  Quaternion Quaternion::normalized() const {
    float mag = magnitude();

    if (mag != 0.0f) {
      return {
        w / mag,
        x / mag,
        y / mag,
        z / mag
        };
    }else{
      return {0, 0, 0, 0};
    }

  }

    Vector3 Quaternion::rotate(const Vector3& vector) const {
    Quaternion vq{0.0f, vector.x, vector.y, vector.z};

    Quaternion conjugate{
      w,
      -x,
      -y,
      -z
    };

    Quaternion result = (*this) * vq * conjugate;

    return {
      result.x,
      result.y,
      result.z
    };
  }

}