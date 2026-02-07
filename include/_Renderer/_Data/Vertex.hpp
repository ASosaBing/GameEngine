#ifndef VERTX_HPP
#define VERTX_HPP
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>


struct Vertex {
    glm::vec3 position;  // Where is it?
    glm::vec3 normal;    // Which way is it facing? (For lighting)
    glm::vec2 texCoords; // Where does the texture go?
    glm::vec3 tangent;   // Essential for Normal Mapping
    // glm::vec3 bitangent; // Optional (can be calculated in shader)
};

#endif
