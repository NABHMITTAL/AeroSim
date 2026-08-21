#pragma once
#include <vector>
#include "vertex.h"
#include "edge.h"
#include "face.h"
#include "surface.h"

namespace aerosim{
  struct Mesh{
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<Face> faces;
    std::vector<Surface> surfaces;
  };
}