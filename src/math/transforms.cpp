#include "transforms.h"

namespace aerosim{
  void Transform::translate(const Vector3& length){
    position = position + length;
  }
  void Transform::rotate(const Quaternion& orientation){
    rotation = rotation*orientation;
  }
  void Transform::scaleUScaleD(const Vector3& size){
    scale.x = scale.x * size.x;
    scale.y = scale.y * size.y;
    scale.z = scale.z * size.z;
  }

  Vector3 Transform::localToWorld(const Vector3& local) const{
    Vector3 scaled;
    scaled.x = local.x * scale.x;
    scaled.y = local.y * scale.y;
    scaled.z = local.z * scale.z;

    Vector3 rotated = rotation.rotate(scaled);

    return rotated + position;
  }

  Vector3 Transform::worldToLocal(const Vector3& world) const {
    Vector3 translated = world - position;

    Vector3 rotated = rotation.conjugate().rotate(translated);

    Vector3 local;
    local.x = rotated.x / scale.x;
    local.y = rotated.y / scale.y;
    local.z = rotated.z / scale.z;

    return local;
}
}