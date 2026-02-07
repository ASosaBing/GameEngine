#ifndef ELEMBUFF_HPP
#define ELEMBUFF_HPP
#include <_Renderer/_GL/Renderer.hpp>
#include <_Renderer/_Data/Vertex.hpp>

class EBO {
public:
  EBO();
  ~EBO();
  EBO(unsigned int vertices[], int length, GLenum usage);
  EBO(const EBO&) = delete;
  EBO& operator=(const EBO&) = delete;
  EBO(EBO&& other) noexcept : m_RendererID(other.m_RendererID) {
      other.m_RendererID = 0; // Set old handle to zero
  }
  EBO& operator=(EBO&& other) noexcept {
      if (this != &other) {
          glDeleteBuffers(1, &m_RendererID); // Delete existing
          m_RendererID = other.m_RendererID;
          other.m_RendererID = 0;
      }
      return *this;
  }



  void Bind() const;
  void UnBind() const;

private:
  unsigned int m_RendererID; 
};




#endif
