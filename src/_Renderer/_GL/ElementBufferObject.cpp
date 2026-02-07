#include<_Renderer/_GL/ElementBufferObject.hpp>
#include <_Tooling/ErrorCheck.hpp>
#include <iostream>


EBO::EBO(){
  GLCall(glGenBuffers(1, &m_RendererID));
}

EBO::~EBO(){
  GLCall(glDeleteBuffers(1, &m_RendererID));
}

EBO::EBO(unsigned int vertices[], int length, GLenum usage){


  GLCall(glGenBuffers(1, &m_RendererID));
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
  GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * length, vertices, usage));
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}


void EBO::Bind() const{
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}
void EBO::UnBind() const {
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
};
