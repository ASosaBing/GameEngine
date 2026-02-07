#include <_Renderer/_GL/VertexBufferObject.hpp>


VBO::VBO()  {
  GLCall(glGenBuffers(1, &m_RendererID));

}



VBO::~VBO(){
  GLCall(glDeleteBuffers(1, &m_RendererID));
}


void VBO::Bind() const{
  GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}
void VBO::UnBind() const {
  GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
};
