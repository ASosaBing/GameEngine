#include<_Renderer/_Mesh/TemporaryMesh.hpp>


TemporaryMesh::TemporaryMesh(float vertices[], unsigned int indices[], VAOLayout layout, int vertexLength, int indexLength, 
       GLenum vertexBufferType, GLenum indexBufferType) : m_VAO{}, m_VBO{vertices, vertexLength, vertexBufferType}, m_EBO{indices, indexLength, indexBufferType},
                                                          component {m_VAO.GetID(), m_VBO.GetID(), m_EBO.GetID(), static_cast<uint32_t>(indexLength)}{
    AssertTypes(vertices);

    m_VAO.Bind();
    m_VBO.Bind();
    m_EBO.Bind();
    m_VAO.EnableAttributes(layout);
    }

  void  TemporaryMesh::Bind(){
    m_VAO.Bind();
  }
  void  TemporaryMesh::UnBind(){
    m_VAO.UnBind();
  }
  
  MeshComponent  TemporaryMesh::GetComponent()
  {
    return component; 
  };
  
