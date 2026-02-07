#ifndef SHADR_HPP
#define SHADR_HPP
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
class Shader{
public:
  Shader(std::string& VertexFilePath, std::string& FragmentFilePath);
  ~Shader();

  void BindProgram();
  void UnBindProgram();

  

private:
  unsigned int m_ProgramRendererID;
  std::string m_VertexShader;
  std::string m_FragmentShader;

  std::string ParseShader(std::string& filePath);
  void CompileShader(unsigned int id, std::string& source, int shaderType);
};


#endif
