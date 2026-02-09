#ifndef VAO_HPP
#define VAO_HPP
#include <_Renderer/_GL/Renderer.hpp>
#include <_Renderer/_Data/VAOLayout.hpp>
class VAO {
public:
  VAO();
  ~VAO();
  VAO(const VAO&) = delete;
  VAO& operator=(const VAO&) = delete;
  VAO(VAO&& other) noexcept : m_RendererID(other.m_RendererID) {
      other.m_RendererID = 0; // Set old handle to zero
  }
  VAO& operator=(VAO&& other) noexcept {
      if (this != &other) {
          glDeleteBuffers(1, &m_RendererID); // Delete existing
          m_RendererID = other.m_RendererID;
          other.m_RendererID = 0;
      }
      return *this;
  }

  void EnableAttributes(VAOLayout layout);

  void Bind() const;
  void UnBind() const;
  unsigned int GetID();


private:
  unsigned int m_RendererID;

};
#endif
