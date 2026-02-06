#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <_OS/Window.hpp>


int main(){
  Window window {Window::GLFWInit(640, 480, "GameEngine")};
  
  

  while(!glfwWindowShouldClose(window.GetGlfwPointer())){
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window.GetGlfwPointer());
    glfwPollEvents();
  }


  Window::GLFWTerminate();
  return 0;
  
}
