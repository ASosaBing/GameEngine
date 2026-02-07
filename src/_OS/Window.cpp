#include <glad/glad.h>
#include <_OS/Window.hpp>
#include <iostream>


//structors
Window::Window(){
  m_Window = glfwCreateWindow(600, 480, "Default Window", nullptr, nullptr);
}

Window::Window(int width, int height, const std::string& title, bool fullscreen){
  m_Window = glfwCreateWindow(width, height, title.c_str(), (fullscreen) ? glfwGetPrimaryMonitor() : nullptr, nullptr);
}

Window::Window(GLFWwindow* window) : m_Window{window}, m_WindowName{glfwGetWindowTitle(window)} {}

Window::~Window(){
  glfwDestroyWindow(m_Window);
}


//accessors
void Window::Title(const std::string& title){
  glfwSetWindowTitle(m_Window, title.c_str());
  m_WindowName = title;
}

const std::string& Window::Title(){
  return m_WindowName;
}

GLFWwindow* Window::GetGlfwPointer(){
  return m_Window;
}

//static member functions
GLFWwindow* Window::GLFWInit(int width, int height, const std::string& title) {
  //set the glfw/opengl version

  //initialize glfw
  if(!glfwInit()){
    throw "failed to initialize glfw";
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


  GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
  glfwMakeContextCurrent(window);
 
  //intialize glad
  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
    throw "failed to initialiaze glad";
  }
  //make monitor refreshrate the fps 
  glfwSwapInterval(1);


  std::cout << "OpenGL successfully loaded" << std::endl;

  return window;
  

}

void Window::GLFWTerminate() {
  glfwTerminate();
}

