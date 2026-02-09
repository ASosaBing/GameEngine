#ifndef RENDR_HPP
#define RENDR_HPP
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <_Renderer/_Data/MeshComponent.hpp>
#include <_Renderer/_GL/Shader.hpp>
class Renderer {
public:




void DrawElements(MeshComponent mesh, Shader& shader);
void DrawElements(MeshComponent mesh, Shader& shader, int indexOffset[] );

private:

};


#endif
