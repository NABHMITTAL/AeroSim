#pragma once

namespace aerosim{
  struct Vector3{

    float x;
    float y;
    float z;

    Vector3 operator+ (const Vector3& other) const;
    Vector3 operator- (const Vector3& other) const;
    Vector3 operator* (const float scaler) const;
    Vector3 operator/ (const float scaler) const;
    float magnitude() const;
    float magnitudeSquared() const;
    Vector3 normalized() const;
    float dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;

  };
  
}