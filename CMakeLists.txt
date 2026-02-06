cmake_minimum_required(VERSION 3.10)


project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED)




add_executable(GameEngine ./src/main.cpp)
target_link_libraries(GameEngine PRIVATE glm::glm)
target_link_libraries(GameEngine PRIVATE glfw)
target_link_libraries(GameEngine PRIVATE glad::glad)
target_link_libraries(GameEngine PRIVATE imgui::imgui)
target_link_libraries(GameEngine PRIVATE OpenGL::GL)

target_include_directories(GameEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)




