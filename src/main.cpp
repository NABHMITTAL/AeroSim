#include <iostream>

#include "geometry/Mesh.h"

int main()
{
    aerosim::Mesh mesh;

    // --------------------
    // Add 4 vertices
    // --------------------

    mesh.vertices.push_back({{0.0, 0.0, 0.0}}); // 0
    mesh.vertices.push_back({{1.0, 0.0, 0.0}}); // 1
    mesh.vertices.push_back({{0.0, 1.0, 0.0}}); // 2
    mesh.vertices.push_back({{1.0, 1.0, 0.0}}); // 3


    // --------------------
    // Add 2 triangular faces
    // --------------------

    mesh.faces.push_back({{0, 1, 2}});
    mesh.faces.push_back({{1, 3, 2}});


    // --------------------
    // Print vertices
    // --------------------

    std::cout << "Vertices: "
              << mesh.vertices.size() << '\n';

    for (std::size_t i = 0; i < mesh.vertices.size(); ++i)
    {
        const auto& position = mesh.vertices[i].vertexPos;

        std::cout << "Vertex " << i
                  << ": ("
                  << position.x << ", "
                  << position.y << ", "
                  << position.z << ")\n";
    }


    // --------------------
    // Print faces
    // --------------------

    std::cout << "\nFaces: "
              << mesh.faces.size() << '\n';

    for (std::size_t i = 0; i < mesh.faces.size(); ++i)
    {
        std::cout << "Face " << i << ": ";

        for (std::size_t vertexIndex : mesh.faces[i].vertices)
        {
            std::cout << vertexIndex << ' ';
        }

        std::cout << '\n';
    }


    // --------------------
    // Verify the indices
    // --------------------

    std::cout << "\nFace 0 uses:\n";

    for (std::size_t vertexIndex : mesh.faces[0].vertices)
    {
        const auto& vertex = mesh.vertices[vertexIndex];

        std::cout << "Vertex "
                  << vertexIndex
                  << " -> ("
                  << vertex.vertexPos.x << ", "
                  << vertex.vertexPos.y << ", "
                  << vertex.vertexPos.z << ")\n";
    }
}