#ifndef MSHCOMPT_HPP
#define MSHCOMPT_HPP

#include "_Renderer/_Data/VAOLayout.hpp"
#include <cstdint>
struct MeshComponent {
  uint32_t vao, vbo, ebo;
  uint32_t indexCount; 
};


#endif

