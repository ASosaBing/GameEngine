#include "_Renderer/_Data/VAOLayout.hpp"
#include "_Renderer/_GL/VertexArrayObject.hpp"
#include "_Renderer/_GL/VertexBufferObject.hpp"
#include <_Renderer/_GL/ElementBufferObject.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <_OS/Window.hpp>
#include <_Renderer/_GL/Shader.hpp>


int main(){ 
  Window window {Window::GLFWInit(640, 480, "GameEngine")};
  {
  float vertices[] = {-0.5f, -0.5f, 0.0f,
                       0.5f, -0.5f, 0.0f,
                       0.5f,  0.5f, 0.0f,
                      -0.5f,  0.5f, 0.0f};

  unsigned int indicies[] = {0, 1, 2, 
                    2, 3, 0}; 


  VAO vao;
  VBO vbo {vertices, 12, GL_STATIC_DRAW};
  EBO ebo {indicies, 6, GL_STATIC_DRAW};
  VAOLayout layout {};
  std::string vsPath = "./res/Shaders/TestShaders/TestVertexShader.glsl";
  std::string fsPath = "./res/Shaders/TestShaders/TestFragmentShader.glsl";
  Shader shader{vsPath, fsPath};





  layout.Push<float>(3, false); 
  vao.Bind();
  vbo.Bind();
  ebo.Bind();
  vao.EnableAttributes(layout);
  shader.BindProgram();

  while(!glfwWindowShouldClose(window.GetGlfwPointer())){
    GLCall(glClear(GL_COLOR_BUFFER_BIT));  

    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0));

    glfwSwapBuffers(window.GetGlfwPointer());
    glfwPollEvents();


  }
  

  }
  Window::GLFWTerminate();
  return 0;
  
}
