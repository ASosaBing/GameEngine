#ifndef WINDW_HPP
#define WINDW_HPP
#include <GLFW/glfw3.h>
#include <string>
class Window {



public:
  
//structors
  Window();
  Window(int width, int height, const std::string& title, bool fullscreen);
  Window(GLFWwindow* window);


  ~Window();


//glfw wrapper methods
  void Title(const std::string& title);
  const std::string& Title();
  GLFWwindow* GetGlfwPointer();
  
//initializing and terimating context functions
  static GLFWwindow* GLFWInit(int width, int height, const std::string& title);  
  static void GLFWTerminate(); 


private:
//according to glfw docs we shouldnt manage the heap
//or anything wrt objects that GLFW gives us
//conversely glfw wont destroy anythign that we give it
  GLFWwindow* m_Window;
  std::string m_WindowName;
};


#endif

