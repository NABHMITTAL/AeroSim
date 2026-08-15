#include "numerical.h"

#include <cmath>
#include <algorithm>

namespace aerosim {

    bool approximatelyEqual(float a, float b, float absoluteTolerance, float relativeTolerance) {
        float difference = std::abs(a - b);

        return difference <=
          absoluteTolerance +
          relativeTolerance *
          std::max(std::abs(a), std::abs(b));
    }

}