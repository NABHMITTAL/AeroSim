#include "Vector3.h"
#include <cmath>
namespace aerosim{
  Vector3 Vector3::operator+(const Vector3& other) const{
    return{
      x+other.x,
      y+other.y,
      z+other.z
    };

  }

  Vector3 Vector3::operator-(const Vector3& other) const{
    return{
      x-other.x,
      y-other.y,
      z-other.z
    };
  }

  Vector3 Vector3::operator*(const float scaler) const{
    return{
      x*scaler,
      y*scaler,
      z*scaler
    };
  }

  Vector3 Vector3::operator/(const float scaler) const{
    return{
      x/scaler,
      y/scaler,
      z/scaler
    };
  }

  float Vector3::magnitude() const{
    float x2 = x*x;
    float y2 = y*y;
    float z2 = z*z;
    return std::sqrt(x2+y2+z2);
  }

  float Vector3::magnitudeSquared() const{
    float x2 = x*x;
    float y2 = y*y;
    float z2 = z*z;
    return x2+y2+z2;
  }

  Vector3 Vector3::normalized() const{
    float mag = this->magnitude();
    return{
      x/mag,
      y/mag,
      z/mag
    };
  }

  float Vector3::dot(const Vector3& other) const{
    float X = x * other.x;
    float Y = y * other.y;
    float Z = z * other.z;
    return X + Y + Z;
  }

  Vector3 Vector3::cross(const Vector3& other) const{
    float X = y*other.z - z*other.y;
    float Y = -(x*other.z - z*other.x);
    float Z = x*other.y - y*other.x;
    return{X,Y,Z};
  }
  
}