#include "_Renderer/_GL/Shader.hpp"
#include <_Renderer/_GL/Renderer.hpp>


void Renderer::DrawElements(MeshComponent mesh, Shader& shader){
  GLCall(glBindVertexArray(mesh.vao));
  shader.BindProgram();



  std::vector<float> data(12);
 


  GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*) 0));
}

void Renderer::DrawElements(MeshComponent mesh, Shader& shader, int indexOffset[] ){
  GLCall(glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_INT, indexOffset));
}
