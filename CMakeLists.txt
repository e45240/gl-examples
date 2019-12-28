cmake_minimum_required(VERSION 3.11...3.15)
if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else ()
    cmake_policy(VERSION 3.15)
endif ()
project(gl-examples
        VERSION 1.0.0
        LANGUAGES CXX
        DESCRIPTION "An example project to learn GL")
set(CMAKE_CXX_STANDARD 11)
include_directories(OpenGL)
include_directories(OpenGL/include)
include_directories(OpenGL/lib)

add_subdirectory("PrimitiveFunction/GL_Lines")
add_subdirectory("PrimitiveFunction/GL_Polygon")
add_subdirectory("PrimitiveFunction/GL_Triangles")
add_subdirectory("PrimitiveFunction/GL_Triangle_Strip")
add_subdirectory("PrimitiveFunction/GL_Triangle_Fan")
add_subdirectory("PrimitiveFunction/GL_Quads")
add_subdirectory("PrimitiveFunction/GL_Quad_Strip")




