#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "Matrix2.h"
#include <iostream>

namespace aerosim{

  //matrix addition
  Matrix2 Matrix2::operator+(const Matrix2& other) const{
    aerosim::Matrix2 added;
    for(int i=0; i<2; i++){
      for (int j=0; j<2; j++){
        added.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return added;
  }

  //matrix subtraction
  Matrix2 Matrix2::operator-(const Matrix2& other) const{
    aerosim::Matrix2 subtracted;
    for(int i=0; i<2; i++){
      for (int j=0; j<2; j++){
        subtracted.data[i][j] = data[i][j] - other.data[i][j];
      }
    }
    return subtracted;
  }

  //matrix scale up
  Matrix2 Matrix2::operator*(float scaler) const{
    aerosim::Matrix2 product;
    for(int i=0; i<2; i++){
      for (int j=0; j<2; j++){
        product.data[i][j] = data[i][j] * scaler;
      }
    }
    return product;
  }

  //matrix scale down
  Matrix2 Matrix2::operator/(float scaler) const{
    aerosim::Matrix2 result;
    if(scaler!=0){
      for(int i=0; i<2; i++){
        for (int j=0; j<2; j++){
          result.data[i][j] = data[i][j] / scaler;
        }
      }
      return result;
    }else{
      throw std::runtime_error("Divided by 0");
    }
  }

  //vector transforation
  Vector2 Matrix2::operator*(const Vector2& other) const{
    aerosim::Vector2 result;

    result.x = data[0][0]*other.x + data[0][1]*other.y;
    result.y = data[1][0]*other.x + data[1][1]*other.y;
    return result;
  }

  //matrix multiplication
  Matrix2 Matrix2::operator*(const Matrix2& other) const{
    aerosim::Matrix2 result;
    for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
        for (int k = 0; k < 2; k++){
          result.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
     return result;
  
  }

  float Matrix2::determinant() const{
    float x = data[0][0]*data[1][1];
    float y = data[0][1]*data[1][0];

    return x-y;
  }

  Matrix2 Matrix2::transpose() const{
    aerosim::Matrix2 result;
    for (int i=0; i<2; i++){
      for (int j=0; j<2; j++){
        result.data[i][j] = data[j][i];
      }
    }
    return result;
  }

  Matrix2 Matrix2::inverse() const{
    float det = determinant();

    if (det == 0.0f){
      throw std::runtime_error("Matrix is not invertible");
    }

    aerosim::Matrix2 result;

    result.data[0][0] = data[1][1];
    result.data[0][1] = -data[0][1];
    result.data[1][0] = -data[1][0];
    result.data[1][1] = data[0][0];

    return result / det;
  }

  Matrix2 Matrix2::Rotate(float angle){
    aerosim::Matrix2 rotationMatrix;
    rotationMatrix.data[0][0] = std::cos(angle);
    rotationMatrix.data[0][1] = (std::sin(angle))*-1; 
    rotationMatrix.data[1][0] = std::sin(angle);
    rotationMatrix.data[1][1] = std::cos(angle);
    return rotationMatrix;
  }

}