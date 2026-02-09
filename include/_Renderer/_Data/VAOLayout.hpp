#ifndef VAOLAYT_HPP
#define VAOLAYT_HPP
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <_Renderer/_Data/Vertex.hpp>
#include <_Tooling/ErrorCheck.hpp>
#include <iostream>
struct VAOLayout{
  short Attributes = 0;
  short Stride = 0;
  short SizeOfType[10];
  short Size[10];
  short Offsets[10];
  GLenum Types[10];
  bool Normalized[10]; 


  template <typename T>
  void Push(int length, bool normalized){
    throw "Invalid type";
  }

  void Display(int attribute){
    ASSERT(attribute < 10);
    std::cout << "Attributes: " << Attributes << std::endl;
    std::cout << "Stride: " << Stride << std::endl;
    std::cout << "Size Type:" << SizeOfType[attribute] << std::endl;
    std::cout << "Size: " << Size[attribute] << std::endl;
    std::cout << "Type: " << Types[attribute] << std::endl;
    std::cout << "offset: " << Offsets[attribute] << std::endl;
    std::cout << "Normalized: " << Normalized[attribute] << std::endl;
  }





};
  template <>
  inline void VAOLayout::Push<Vertex>(int length, bool normalized){
    ASSERT((Attributes < 10) && length > 0 && length < 5);
    Attributes++;
    Stride += sizeof(Vertex) * length;
    SizeOfType[Attributes - 1] = sizeof(Vertex);
    Size[Attributes - 1] = length;
    Types[Attributes - 1] = GL_FLOAT;
    int offset = 0;
    for(int i = 0 ; i < Attributes; i++){
      offset += SizeOfType[i] * Size[i];
    }
    Offsets[Attributes - 1] = offset;
    Normalized[Attributes - 1] = normalized;

  };



  template <>
  inline void VAOLayout::Push<unsigned char>(int length, bool normalized){
    ASSERT((Attributes < 10) && length > 0 && length < 5);
    Attributes++;
    Stride += sizeof(unsigned char);
    SizeOfType[Attributes - 1] = sizeof(unsigned char) * length;
    Size[Attributes - 1] = length;
    Types[Attributes - 1] = GL_UNSIGNED_BYTE;
    int offset = 0;
    for(int i = 0 ; i < Attributes; i++){
      offset += SizeOfType[i] * Size[i];
    }
    Offsets[Attributes - 1] = offset;
    Normalized[Attributes - 1] = normalized;

  }

  template <>
  inline void VAOLayout::Push<short>(int length, bool normalized){
    ASSERT((Attributes < 10) && length > 0 && length < 5);
    Attributes++;
    Stride += sizeof(short) * length;
    SizeOfType[Attributes - 1] = sizeof(short);
    Size[Attributes - 1] = length;
    Types[Attributes - 1] = GL_SHORT;
    int offset = 0;
    for(int i = 0 ; i < Attributes; i++){
      offset += SizeOfType[i] * Size[i];
    }
    Offsets[Attributes - 1] = offset;
    Normalized[Attributes - 1] = normalized;
  }

  template <>
  inline void  VAOLayout::Push<float>(int length, bool normalized){
    ASSERT((Attributes < 10) && length > 0 && length < 5);
    Attributes++;
    int offset = 0;
    for(int i = 0 ; i < Attributes; i++){
      offset += SizeOfType[i] * Size[i];
    }
    Stride += sizeof(float) * length;
    SizeOfType[Attributes - 1] = sizeof(float);
    Size[Attributes - 1] = length;
    Types[Attributes - 1] = GL_FLOAT;
    
    Offsets[Attributes - 1] = offset;
    Normalized[Attributes - 1] = normalized;  

   

  }

#endif
