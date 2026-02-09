#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <_OS/Window.hpp>
#include <_Renderer/_GL/Renderer.hpp>
#include <_Renderer/_GL/Shader.hpp>
#include <_Renderer/_Mesh/TemporaryMesh.hpp>


int main(){ 


  Window window {Window::GLFWInit(640, 480, "GameEngine")};
  {
  float vertices[] = {-0.5f, -0.5f, 0.0f,
                       0.5f, -0.5f, 0.0f,
                       0.5f,  0.5f, 0.0f,
                      -0.5f,  0.5f, 0.0f};

  unsigned int indices[] = {0, 1, 2, 
                             2, 3, 0}; 


  Renderer rendr{};



  std::string vsPath = "./res/Shaders/TestShaders/TestVertexShader.glsl";
  std::string fsPath = "./res/Shaders/TestShaders/TestFragmentShader.glsl";
  Shader shader{vsPath, fsPath};

  VAOLayout layout {};
  layout.Push<float>(3, false); 


  TemporaryMesh mesh{vertices, indices, layout, 12, 6, GL_STATIC_DRAW, GL_STATIC_DRAW};
  MeshComponent meshcomp = mesh.GetComponent();

  while(!glfwWindowShouldClose(window.GetGlfwPointer())){
    GLCall(glClear(GL_COLOR_BUFFER_BIT));  
    
    rendr.DrawElements(meshcomp, shader);

    //GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0));

    glfwSwapBuffers(window.GetGlfwPointer());
    glfwPollEvents();


  }

  }
  Window::GLFWTerminate();
  return 0;
  
}
