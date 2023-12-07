cmake_minimum_required(VERSION 3.21)
project(TucanCore)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_library(TucanCore SHARED Bridges/VBO.cpp Bridges/VBO.h Bridges/EBO.cpp Bridges/EBO.h Bridges/VAO.cpp Bridges/VAO.h Math/Vector3.cpp Math/Vector3.h Math/MathF.cpp Math/MathF.h Math/Matrix4x4.cpp Math/Matrix4x4.h Math/Quaternion.cpp Math/Quaternion.h Math/Vector4.cpp Math/Vector4.h Math/Vector.h Math/Matrix.h Math/Vector.cpp Math/Matrix.cpp)

include_directories(${GLEW_INCLUDE_DIRS})

target_link_libraries(TucanCore ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})
target_link_libraries(TucanCore -lopengl32 -g)
