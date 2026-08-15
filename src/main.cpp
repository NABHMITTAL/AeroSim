#include <iostream>
#include <iomanip>
#include <cmath>

#include "math/transforms.h"

int main() {
    using namespace aerosim;

    std::cout << std::fixed << std::setprecision(3);

    Transform transform;

    // Transform setup
    transform.translate({10.0f, 5.0f, 0.0f});
    transform.scaleUScaleD({2.0f, 2.0f, 2.0f});

    // 90 degree rotation around Z
    float angle = 3.14159265359f / 2.0f;

    Quaternion rotation(
        std::cos(angle / 2.0f),
        0.0f,
        0.0f,
        std::sin(angle / 2.0f)
    );

    transform.rotate(rotation);

    // Original local point
    Vector3 localPoint{1.0f, 0.0f, 0.0f};

    // Local -> World
    Vector3 worldPoint = transform.localToWorld(localPoint);

    // World -> Local
    Vector3 recoveredLocal = transform.worldToLocal(worldPoint);

    std::cout << "=== Coordinate Conversion ===\n";

    std::cout << "Original local point: ("
              << localPoint.x << ", "
              << localPoint.y << ", "
              << localPoint.z << ")\n";

    std::cout << "World point: ("
              << worldPoint.x << ", "
              << worldPoint.y << ", "
              << worldPoint.z << ")\n";

    std::cout << "Recovered local point: ("
              << recoveredLocal.x << ", "
              << recoveredLocal.y << ", "
              << recoveredLocal.z << ")\n";

    return 0;
}