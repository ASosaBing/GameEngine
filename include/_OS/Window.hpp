#ifndef WINDW_HPP
#define WINDW_HPP
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
class Window {



public:
  
//structors
  Window();
  Window(int width, int height, const std::string& title, bool fullscreen);
  ~Window();


//glfw wrapper methods
  void SetTitle(const std::string& title);

  
//initializing and terimating context functions
  static void GLFWInit();  
  static void GLFWTerminate(); 


private:
//according to glfw docs we shouldnt manage the heap
//or anything wrt objects that GLFW gives us
//conversely glfw wont destroy anythign that we give it
  GLFWwindow* window;
  std::string windowName;
};


#endif

