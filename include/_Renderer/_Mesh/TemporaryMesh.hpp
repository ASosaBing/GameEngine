#ifndef MESH_HPP
#define MESH_HPP
#include "_Renderer/_GL/Renderer.hpp"
#include "_Tooling/ErrorCheck.hpp"
#include <_Renderer/_GL/VertexArrayObject.hpp>
#include <_Renderer/_GL/VertexBufferObject.hpp>
#include <_Renderer/_GL/ElementBufferObject.hpp>



class TemporaryMesh{
public:
  TemporaryMesh(float vertices[], unsigned int indices[], VAOLayout layout, int vertexLength, int indexLength, 
       GLenum vertexBufferType, GLenum indexBufferType);

  void Bind();
  void UnBind();
  
  MeshComponent GetComponent(); 
  
private:
  VAO m_VAO;
  VBO m_VBO; 
  EBO m_EBO;
  MeshComponent component;
};



#endif
