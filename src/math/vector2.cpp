#include "Vector2.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

namespace aerosim{
  Vector2 Vector2::operator+(const Vector2& other) const{
    return{
      x+other.x,
      y+other.y,
    };

  }

  Vector2 Vector2::operator-(const Vector2& other) const{
    return{
      x-other.x,
      y-other.y,
    };
  }

  Vector2 Vector2::operator*(const float scaler) const{
    return{
      x*scaler,
      y*scaler,
    };
  }

  Vector2 Vector2::operator/(const float scaler) const{
    if(scaler != 0){
      return{
        x/scaler,
        y/scaler,
      };
    }else{
      throw std::runtime_error("Divide by 0");
    }
  }

  float Vector2::magnitude() const{
    float x2 = x*x;
    float y2 = y*y;
    return std::sqrt(x2+y2);
  }

  float Vector2::magnitudeSquared() const{
    float x2 = x*x;
    float y2 = y*y;
    return x2+y2;
  }

  Vector2 Vector2::normalized() const{
    float mag = this->magnitude();
    if(mag != 0.0f){
      return{
        x/mag,
        y/mag,
      };
    }else{
      return {0,0};
    }
  }

  float Vector2::dot(const Vector2& other) const{
    float X = x * other.x;
    float Y = y * other.y;
    return X + Y;
  }

  float Vector2::cross(const Vector2& other) const{
    return x * other.y - y * other.x;
  }

  float Vector2::distanceSquared(const Vector2& other) const{
    aerosim::Vector2 sub = other - *this;
    return {
      sub.x*sub.x +
      sub.y*sub.y 
    };
  }

  float Vector2::distance(const Vector2& other) const{
    return {std::sqrt(this->distanceSquared(other))};
  }

  float Vector2::angleBetween(const Vector2& other) const{
    return std::atan2(this->cross(other), this->dot(other));
  }
  
}