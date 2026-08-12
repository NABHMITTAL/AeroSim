#include <iostream>
#include <iomanip>

#include "math/matrix2.h"
#include "math/matrix2.h"

using namespace aerosim;

void printVector(const Vector2& v) {
    std::cout << "(" << v.x << ", " << v.y << ")\n";
}

void printMatrix(const Matrix2& m) {
    for (int i = 0; i < 2; i++) {
        std::cout << m.data[i][0] << " "
                  << m.data[i][1] << "\n";
    }
}

int main() {

    std::cout << std::fixed << std::setprecision(3);

    // =========================
    // Vector2
    // =========================

    Vector2 a{3, 4};
    Vector2 b{1, 2};

    std::cout << "=== Vector2 ===\n";

    std::cout << "Addition: ";
    printVector(a + b);

    std::cout << "Subtraction: ";
    printVector(a - b);

    std::cout << "Multiplication: ";
    printVector(a * 2.0f);

    std::cout << "Division: ";
    printVector(a / 2.0f);

    std::cout << "Magnitude: "
              << a.magnitude() << "\n";

    std::cout << "Magnitude squared: "
              << a.magnitudeSquared() << "\n";

    std::cout << "Normalized: ";
    printVector(a.normalized());

    std::cout << "Dot: "
              << a.dot(b) << "\n";

    std::cout << "Cross: "
              << a.cross(b) << "\n";

    std::cout << "Distance squared: "
              << a.distanceSquared(b) << "\n";

    std::cout << "Distance: "
              << a.distance(b) << "\n";

    std::cout << "Angle between: "
              << a.angleBetween(b) << " radians\n";


    // =========================
    // Matrix2
    // =========================

    Matrix2 A;
    A.data[0][0] = 1;
    A.data[0][1] = 2;
    A.data[1][0] = 3;
    A.data[1][1] = 4;

    Matrix2 B;
    B.data[0][0] = 5;
    B.data[0][1] = 6;
    B.data[1][0] = 7;
    B.data[1][1] = 8;

    std::cout << "\n=== Matrix2 ===\n";

    std::cout << "A:\n";
    printMatrix(A);

    std::cout << "\nB:\n";
    printMatrix(B);

    std::cout << "\nA + B:\n";
    printMatrix(A + B);

    std::cout << "\nA - B:\n";
    printMatrix(A - B);

    std::cout << "\nA * 2:\n";
    printMatrix(A * 2.0f);

    std::cout << "\nA / 2:\n";
    printMatrix(A / 2.0f);

    Vector2 v{2, 3};

    std::cout << "\nA * Vector2:\n";
    printVector(A * v);

    std::cout << "\nA * B:\n";
    printMatrix(A * B);

    std::cout << "\nDeterminant of A: "
              << A.determinant() << "\n";

    std::cout << "\nTranspose of A:\n";
    printMatrix(A.transpose());

    std::cout << "\nInverse of A:\n";
    printMatrix(A.inverse());

    std::cout << "\nA * A.inverse():\n";
    printMatrix(A * A.inverse());


    // =========================
    // Rotation
    // =========================

    constexpr float PI = 3.14159265358979323846f;
    float angle = PI / 2.0f;

    Matrix2 rotation = Matrix2::Rotate(angle);

    Vector2 xAxis{1, 0};

    std::cout << "\n=== Rotation ===\n";

    std::cout << "90 degree rotation matrix:\n";
    printMatrix(rotation);

    std::cout << "\n(1,0) rotated 90 degrees:\n";
    printVector(rotation * xAxis);

    return 0;
}