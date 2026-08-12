#include <iostream>
#include "math/quaternion.h"
#include "math/vector3.h"

using namespace aerosim;

void printVector(const Vector3& v) {
    std::cout << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";
}

void printQuaternion(const Quaternion& q) {
    std::cout << "("
              << q.w << ", "
              << q.x << ", "
              << q.y << ", "
              << q.z << ")\n";
}

int main() {

    constexpr float PI = 3.14159265358979323846f;

    // =========================
    // Quaternion
    // =========================

    Quaternion q{1, 2, 3, 4};

    std::cout << "=== Quaternion ===\n";

    std::cout << "q: ";
    printQuaternion(q);

    std::cout << "Magnitude: "
              << q.magnitude() << "\n";

    std::cout << "Normalized: ";
    printQuaternion(q.normalized());


    // =========================
    // Quaternion multiplication
    // =========================

    Quaternion q1{1, 2, 3, 4};
    Quaternion q2{5, 6, 7, 8};

    std::cout << "\n=== Quaternion Multiplication ===\n";

    std::cout << "q1 * q2: ";
    printQuaternion(q1 * q2);


    // =========================
    // 90 degree rotations
    // =========================

    std::cout << "\n=== Quaternion Rotation ===\n";

    // 90 degrees around Z
    Quaternion zRotation{
        std::cos(PI / 4.0f),
        0,
        0,
        std::sin(PI / 4.0f)
    };

    Vector3 xAxis{1, 0, 0};

    std::cout << "X axis rotated 90 degrees around Z: ";
    printVector(zRotation.rotate(xAxis));


    // 90 degrees around Y
    Quaternion yRotation{
        std::cos(PI / 4.0f),
        0,
        std::sin(PI / 4.0f),
        0
    };

    std::cout << "X axis rotated 90 degrees around Y: ";
    printVector(yRotation.rotate(xAxis));


    // 90 degrees around X
    Quaternion xRotation{
        std::cos(PI / 4.0f),
        std::sin(PI / 4.0f),
        0,
        0
    };

    Vector3 yAxis{0, 1, 0};

    std::cout << "Y axis rotated 90 degrees around X: ";
    printVector(xRotation.rotate(yAxis));


    return 0;
}