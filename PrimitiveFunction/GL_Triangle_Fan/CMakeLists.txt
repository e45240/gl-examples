add_custom_target(glut_gl_triangle_fan_dll COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/OpenGL/dll/glut32.dll ${CMAKE_CURRENT_BINARY_DIR})

add_executable(GL_Triangle_Fan main.cpp)
target_link_libraries(GL_Triangle_Fan opengl32 glu32 ${PROJECT_SOURCE_DIR}/OpenGL/lib/glut32.lib)
add_dependencies(GL_Triangle_Fan glut_gl_triangle_fan_dll)