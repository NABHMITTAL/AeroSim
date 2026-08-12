#include "core/Application.h"
#include "math/vector3.h"
#include <iostream>
#include "math/matrix3.h"

int main(){
    aerosim::Application application;
    application.run();

    aerosim::Matrix3 matrix;
    matrix.data[0][0] = 1.0f;
    matrix.data[0][1] = 2.0f;
    matrix.data[0][2] = 3.0f;

    matrix.data[1][0] = 0.0f;
    matrix.data[1][1] = 1.0f;
    matrix.data[1][2] = 4.0f;

    matrix.data[2][0] = 5.0f;
    matrix.data[2][1] = 6.0f;
    matrix.data[2][2] = 0.0f;

    aerosim::Matrix3 inverse = matrix.inverse();
    aerosim::Matrix3 identity = matrix * inverse;

    std::cout << "Original:\n";

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << matrix.data[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nInverse:\n";

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << inverse.data[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nMatrix * Inverse:\n";

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << identity.data[i][j] << " ";
        }
        std::cout << "\n";
    }
        

    return 0;
}