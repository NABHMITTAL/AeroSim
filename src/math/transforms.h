#pragma once
#include "vector3.h"
#include "quaternion.h"

namespace aerosim{
  struct Transform{
    Vector3 position;
    Vector3 scale;
    Quaternion rotation;

    Transform(){
      position.x = 0;
      position.y = 0;
      position.z = 0;

      rotation.w = 1;
      rotation.x = 0;
      rotation.y = 0;
      rotation.z = 0;



      scale.x = 1;
      scale.y = 1;
      scale.z = 1;

      
    }
    void translate(const Vector3& length);
    void rotate(const Quaternion& orientation);
    void scaleUScaleD(const Vector3& size);
    Vector3 localToWorld(const Vector3& local) const;
     Vector3 worldToLocal(const Vector3& world) const;

  };
}