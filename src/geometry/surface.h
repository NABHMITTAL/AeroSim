#pragma once
#include <vector>
#include <cstddef>

namespace aerosim{
  struct Surface{
    std::vector<std::size_t> faces;
  };
}