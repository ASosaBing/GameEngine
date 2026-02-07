#include <_Tooling/ErrorCheck.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <_Renderer/_Data/Vertex.hpp>

void GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line){
  while(GLenum error = glGetError()){
    std::cout << "[OpenGL Error] (" << std::hex << error << std::dec << ") "
              << function << " " << file << ": " << line << std::endl;
    return false;
  }
  return true;
}


