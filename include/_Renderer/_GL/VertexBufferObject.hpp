#ifndef VRTXBUFF_HPP
#define VRTXBUFF_HPP
#include <_Renderer/_GL/Renderer.hpp>
#include <_Tooling/ErrorCheck.hpp>
#include <_Renderer/_Data/Vertex.hpp>
class VBO {
public:
  //
  VBO();
  ~VBO();
  VBO(const VBO&) = delete;
  VBO& operator=(const VBO&) = delete;
  VBO(VBO&& other) noexcept : m_RendererID(other.m_RendererID) {
      other.m_RendererID = 0; // Set old handle to zero
  }
  VBO& operator=(VBO&& other) noexcept {
      if (this != &other) {
          glDeleteBuffers(1, &m_RendererID); // Delete existing
          m_RendererID = other.m_RendererID;
          other.m_RendererID = 0;
      }
      return *this;
  }
  
  unsigned int GetID();



  template<typename T>
  VBO(T vertices[], int length, GLenum usage){
    AssertTypes(vertices);
    
    GLCall(glGenBuffers(1, &m_RendererID)); 
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(T) * length, vertices, usage));

    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
  }  
  void Bind() const;
  void UnBind() const;
private:
  unsigned int m_RendererID; 
};




#endif
