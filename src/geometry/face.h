#pragma once
#include "vertex.h"
#include <vector>
#include <cstddef>

namespace aerosim{
  struct Face{
    std::vector<std::size_t> vertices;
  };
}