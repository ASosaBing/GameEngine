
#include <_Renderer/_GL/Shader.hpp>
#include <_Tooling/ErrorCheck.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
Shader::Shader(std::string& VertexFilePath, std::string& FragmentFilePath){
  GLCall(unsigned int vsID = glCreateShader(GL_VERTEX_SHADER));
  GLCall(unsigned int fsID = glCreateShader(GL_FRAGMENT_SHADER));
  GLCall(m_ProgramRendererID = glCreateProgram());
  
  GLCall(m_VertexShader = ParseShader(VertexFilePath));
  GLCall(m_FragmentShader = ParseShader(FragmentFilePath));
 

  //shader 0 is a vertex shader, 1 is a fragment shader
  CompileShader(vsID, m_VertexShader, 0);
  CompileShader(fsID, m_FragmentShader, 1);


  GLCall(glAttachShader(m_ProgramRendererID, vsID));
  GLCall(glAttachShader(m_ProgramRendererID, fsID));

  GLCall(glLinkProgram(m_ProgramRendererID));
  int success;
  glGetProgramiv(m_ProgramRendererID, GL_LINK_STATUS, &success);
  if (!success) {
    GLchar infoLog[512]; // Adjust size as needed
    glGetProgramInfoLog(m_ProgramRendererID, 512, NULL, infoLog);
    // Print the error log to console
    std::cout << "ERROR:PROGRAM::LINKING_FAILED";
  }

  GLCall(glDeleteShader(vsID));
  GLCall(glDeleteShader(fsID));      
}

Shader::~Shader(){
  GLCall(glDeleteProgram(m_ProgramRendererID));

}


std::string Shader::ParseShader(std::string& filePath){
  std::ifstream stream{filePath};
  std::string line;
  std::stringstream ss{};
  while(getline(stream, line)){ 
      ss << line << "\n";
  }


  return ss.str();
}


void Shader::CompileShader(unsigned int id, std::string& source, int shaderType){  
  const char* src = source.c_str();
  GLCall(glShaderSource(id, 1, &src, NULL));
  GLCall(glCompileShader(id));

  int result;
  GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
  if(result == GL_FALSE){
    int length;
    GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));


    char* message = (char*)alloca(length * sizeof(char));
    GLCall(glGetShaderInfoLog(id, length, &length, message));
    std::cout << "Failed to compile " << ((id == 0) ? "vertex " : "fragment ") << "shader!" << std::endl;
    std::cout << message << std::endl;
    GLCall(glDeleteShader(id));
  }
}

void Shader::BindProgram(){
  GLCall(glUseProgram(m_ProgramRendererID));
}

void Shader::UnBindProgram(){
  GLCall(glUseProgram(0));
}
