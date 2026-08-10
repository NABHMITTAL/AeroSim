#include "core/Application.h"
#include "math/vector3.h"
#include <iostream>

int main(){
    aerosim::Application application;
    application.run();

    aerosim::Vector3 a{3.0f, 4.0f, 0.0f}; 
    aerosim::Vector3 b{1.0f, 2.0f, 3.0f}; 
    aerosim::Vector3 addition = a + b; 
    aerosim::Vector3 subtraction = a - b; 
    aerosim::Vector3 multiplication = a * 2.0f; 
    aerosim::Vector3 division = a / 2.0f; 
    aerosim::Vector3 normalized = a.normalized(); 
    float magnitude = a.magnitude(); 
    float dot = a.dot(b); 
    aerosim::Vector3 cross = a.cross(b); 
    std::cout << "Addition: (" 
        << addition.x << ", " 
        << addition.y << ", " 
        << addition.z << ")\n"; 

    std::cout << "Subtraction: (" 
        << subtraction.x << ", " 
        << subtraction.y << ", " 
        << subtraction.z << ")\n"; 
        std::cout << "Multiplication: (" 
        << multiplication.x << ", " 
        << multiplication.y << ", " 
        << multiplication.z << ")\n"; 
        std::cout << "Division: (" 
        << division.x << ", " 
        << division.y << ", " 
        << division.z << ")\n"; 
        std::cout << "Magnitude: " 
        << magnitude << "\n"; std::cout 
        << "Normalized: (" 
        << normalized.x << ", " 
        << normalized.y << ", " 
        << normalized.z << ")\n"; 
        std::cout << "Dot: " << dot << "\n"; 
        std::cout << "Cross: (" 
        << cross.x << ", " 
        << cross.y << ", " 
        << cross.z << ")\n";
    

    return 0;
}