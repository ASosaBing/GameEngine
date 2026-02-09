#include<_Tooling/ErrorCheck.hpp>
#include <_Renderer/_GL/VertexArrayObject.hpp>
#include <iostream>

VAO::VAO(){
  GLCall(glGenVertexArrays(1, &m_RendererID));
  GLCall(glBindVertexArray(m_RendererID));
}

VAO::~VAO() {
  GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VAO::Bind() const {
  GLCall(glBindVertexArray(m_RendererID));
}

void VAO::UnBind() const {
  GLCall(glBindVertexArray(0));
}

void VAO::EnableAttributes(VAOLayout layout){
  for(int i = 0; i < layout.Attributes; i++){
    GLCall(glVertexAttribPointer(i, layout.Size[i], layout.Types[i], layout.Normalized[i],
                                layout.Stride, (void*)((intptr_t)layout.Offsets[i])));
    GLCall(glEnableVertexAttribArray(i));
  }

}


unsigned int VAO::GetID(){
  return m_RendererID;
}


