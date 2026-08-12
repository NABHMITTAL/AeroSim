#pragma once

namespace aerosim{
  struct Vector2{

    float x;
    float y;

    Vector2 operator+ (const Vector2& other) const;
    Vector2 operator- (const Vector2& other) const;
    Vector2 operator* (const float scaler) const;
    Vector2 operator/ (const float scaler) const;
    float magnitude() const;
    float magnitudeSquared() const;
    Vector2 normalized() const;
    float dot(const Vector2& other) const;
    float cross(const Vector2& other) const;
    float distanceSquared(const Vector2& other) const;
    float distance(const Vector2& other) const;
    float angleBetween(const Vector2& other) const;
  };
  
}