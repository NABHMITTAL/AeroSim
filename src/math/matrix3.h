#pragma once
#include "vector3.h"

namespace aerosim{
  struct Matrix3{
    float data[3][3];

    Matrix3(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                data[i][j] = 0.0f;
            }
        }
    }
    
    //basic operations
    Matrix3 operator+(const Matrix3& other) const;
    Matrix3 operator-(const Matrix3& other) const;
    Matrix3 operator*(float scaler) const;
    Matrix3 operator/(float scaler) const;
    
    //matrix specific operations
    Vector3 operator*(const Vector3& other) const;
    Matrix3 operator*(const Matrix3& other) const;
    
    //non operative commands
    float determinant() const;
    Matrix3 transpose() const;
    Matrix3 inverse() const;

    static Matrix3 RotateX(float angle);
    static Matrix3 RotateY(float angle);
    static Matrix3 RotateZ(float angle);

  };
}