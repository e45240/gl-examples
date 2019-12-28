add_custom_target(glut_gl_triangle_strip_dll COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/OpenGL/dll/glut32.dll ${CMAKE_CURRENT_BINARY_DIR})

add_executable(GL_Triangle_Strip main.cpp)
target_link_libraries(GL_Triangle_Strip opengl32 glu32 ${PROJECT_SOURCE_DIR}/OpenGL/lib/glut32.lib)
add_dependencies(GL_Triangle_Strip glut_gl_triangle_strip_dll)