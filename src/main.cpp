#include <iostream>
#include <iomanip>

#include "math/numerical.h"

int main() {
    using namespace aerosim;

    std::cout << std::boolalpha;

    const float absTol = 0.00001f;
    const float relTol = 0.0001f;

    std::cout << "=== Numerical Foundations ===\n\n";

    std::cout << "1. Exactly equal:\n";
    std::cout << approximatelyEqual(
        1.0f, 1.0f, absTol, relTol
    ) << "\n\n";

    std::cout << "2. Small difference:\n";
    std::cout << approximatelyEqual(
        1.0f, 1.000001f, absTol, relTol
    ) << "\n\n";

    std::cout << "3. Difference outside tolerance:\n";
    std::cout << approximatelyEqual(
        1.0f, 1.1f, absTol, relTol
    ) << "\n\n";

    std::cout << "4. Near zero:\n";
    std::cout << approximatelyEqual(
        0.000001f, 0.000002f, absTol, relTol
    ) << "\n\n";

    std::cout << "5. Large values:\n";
    std::cout << approximatelyEqual(
        1000000.0f, 1000000.05f, absTol, relTol
    ) << "\n\n";

    std::cout << "6. Large difference:\n";
    std::cout << approximatelyEqual(
        1000000.0f, 1000100.0f, absTol, relTol
    ) << "\n\n";

    std::cout << "7. Floating-point example:\n";

    float a = 0.1f;
    float b = 0.2f;
    float expected = 0.3f;
    float result = a + b;

    std::cout << std::setprecision(10);

    std::cout << "0.1 + 0.2 = " << result << "\n";
    std::cout << "Expected   = " << expected << "\n";
    std::cout << "Approximately equal: "
              << approximatelyEqual(
                     result,
                     expected,
                     absTol,
                     relTol
                 )
              << "\n";

    return 0;
}