#ifndef ERR_HPP
#define ERR_HPP
#include<_Renderer/_Data/Vertex.hpp>

#if defined(_WIN32) | defined(_WIN64)
#define ASSERT(x)                                                              \
  if (!(x))                                                                    \
    __debug_break();
#endif
#if (defined(__APPLE__) || defined(__MACH__) || defined(__linux__))
#define ASSERT(x)                                                              \
  if (!(x))                                                                    \
    __builtin_trap();
#endif

#define GLCall(x)                                                              \
  GLClearError();                                                              \
  x;                                                                           \
  ASSERT(GLLogCall(#x, __FILE__, __LINE__));

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
template <typename T>
void AssertTypes(T type) {
  const bool types = std::is_same_v<T, Vertex*> || std::is_same_v<T, unsigned char*> 
            || std::is_same_v<T, float*>  || std::is_same_v<T, short*>;
  static_assert(types, "invalid type!");
   
} 


#endif
