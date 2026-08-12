#pragma once
#include "vector2.h"

namespace aerosim{
  struct Matrix2{
    float data[2][2];

    Matrix2(){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                data[i][j] = 0.0f;
            }
        }
    }
    
    //basic operations
    Matrix2 operator+(const Matrix2& other) const;
    Matrix2 operator-(const Matrix2& other) const;
    Matrix2 operator*(float scaler) const;
    Matrix2 operator/(float scaler) const;
    
    //matrix specific operations
    Vector2 operator*(const Vector2& other) const;
    Matrix2 operator*(const Matrix2& other) const;
    
    //non operative commands
    float determinant() const;
    Matrix2 transpose() const;
    Matrix2 inverse() const;

    static Matrix2 Rotate(float angle);

  };
}