#pragma once
#include "vertex.h"
#include <cstddef>

namespace aerosim{
  struct Edge{
    std::size_t v1;
    std::size_t v2;
  };
}