#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "matrix3.h"
#include <iostream>

namespace aerosim{

  //matrix addition
  Matrix3 Matrix3::operator+(const Matrix3& other) const{
    aerosim::Matrix3 added;
    for(int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        added.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return added;
  }

  //matrix subtraction
  Matrix3 Matrix3::operator-(const Matrix3& other) const{
    aerosim::Matrix3 subtracted;
    for(int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        subtracted.data[i][j] = data[i][j] - other.data[i][j];
      }
    }
    return subtracted;
  }

  //matrix scale up
  Matrix3 Matrix3::operator*(float scaler) const{
    aerosim::Matrix3 product;
    for(int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        product.data[i][j] = data[i][j] * scaler;
      }
    }
    return product;
  }

  //matrix scale down
  Matrix3 Matrix3::operator/(float scaler) const{
    aerosim::Matrix3 result;
    if(scaler!=0){
      for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          result.data[i][j] = data[i][j] / scaler;
        }
      }
      return result;
    }else{
      throw std::runtime_error("Divided by 0");
    }
  }

  //vector transforation
  Vector3 Matrix3::operator*(const Vector3& other) const{
    aerosim::Vector3 result;

    result.x = data[0][0]*other.x + data[0][1]*other.y + data[0][2]*other.z;
    result.y = data[1][0]*other.x + data[1][1]*other.y + data[1][2]*other.z;
    result.z = data[2][0]*other.x + data[2][1]*other.y + data[2][2]*other.z;
    return result;
  }

  //matrix multiplication
  Matrix3 Matrix3::operator*(const Matrix3& other) const{
    aerosim::Matrix3 result;
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        for (int k = 0; k < 3; k++){
          result.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
     return result;
  
  }

  float Matrix3::determinant() const{
    float x = data[0][0]*((data[1][1] * data[2][2])-(data[1][2] * data[2][1]));
    float y = data[0][1]*((data[1][0] * data[2][2])-(data[1][2] * data[2][0]));
    float z = data[0][2]*((data[1][0] * data[2][1])-(data[1][1] * data[2][0]));

    return x-y+z;
  }

  Matrix3 Matrix3::transpose() const{
    aerosim::Matrix3 result;
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        result.data[i][j] = data[j][i];
      }
    }
    return result;
  }

  Matrix3 Matrix3::inverse() const{
    aerosim::Matrix3 result;
    int countPos = 0;
    aerosim::Matrix3 coFactor;
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        float miniMat[4];
        int miniMatIndex = 0;
        for (int k = 0; k < 3; k++){
          for (int l = 0; l < 3; l++){
            if(i!=k){
              if(j!=l){
                miniMat[miniMatIndex] = data[k][l];
                miniMatIndex++;
              }
            }
          }
        }
        
        coFactor.data[i][j] = miniMat[0]*miniMat[3] - miniMat[1]*miniMat[2];
        if((i+j) % 2 != 0){
          coFactor.data[i][j] *= -1;
        }
      }
      
    }

    
    aerosim::Matrix3 adjent = coFactor.transpose();
    if (this->determinant() != 0){
      return adjent/this->determinant();
    }
  }

    Matrix3 Matrix3::RotateX(float angle){
    aerosim::Matrix3 rotationMatrix;
    rotationMatrix.data[0][0] = 1; 
    rotationMatrix.data[0][1] = 0; 
    rotationMatrix.data[0][2] = 0; 
    rotationMatrix.data[1][0] = 0; 
    rotationMatrix.data[1][1] = std::cos(angle); 
    rotationMatrix.data[1][2] = (std::sin(angle))*-1; 
    rotationMatrix.data[2][0] = 0; 
    rotationMatrix.data[2][1] = std::sin(angle); 
    rotationMatrix.data[2][2] = std::cos(angle); 

    return rotationMatrix;

  }

    Matrix3 Matrix3::RotateY(float angle){
    aerosim::Matrix3 rotationMatrix;
    rotationMatrix.data[0][0] = std::cos(angle); 
    rotationMatrix.data[0][1] = 0; 
    rotationMatrix.data[0][2] = std::sin(angle); 
    rotationMatrix.data[1][0] = 0; 
    rotationMatrix.data[1][1] = 1; 
    rotationMatrix.data[1][2] = 0; 
    rotationMatrix.data[2][0] = (std::sin(angle))*-1; 
    rotationMatrix.data[2][1] = 0; 
    rotationMatrix.data[2][2] = std::cos(angle); 

    return rotationMatrix;

  }

    Matrix3 Matrix3::RotateZ(float angle){
    aerosim::Matrix3 rotationMatrix;
    rotationMatrix.data[0][0] = std::cos(angle); 
    rotationMatrix.data[0][1] = (std::sin(angle))*-1; 
    rotationMatrix.data[0][2] = 0; 
    rotationMatrix.data[1][0] = std::sin(angle); 
    rotationMatrix.data[1][1] = std::cos(angle); 
    rotationMatrix.data[1][2] = 0; 
    rotationMatrix.data[2][0] = 0; 
    rotationMatrix.data[2][1] = 0; 
    rotationMatrix.data[2][2] = 1; 

    return rotationMatrix;

  }

}