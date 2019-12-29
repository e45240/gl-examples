add_custom_target(glut_draw_cube_with_vertex_array_dll COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/OpenGL/dll/glut32.dll ${CMAKE_CURRENT_BINARY_DIR})

add_executable(DrawCubeWithVertexArray main.cpp)
target_link_libraries(DrawCubeWithVertexArray opengl32 glu32 ${PROJECT_SOURCE_DIR}/OpenGL/lib/glut32.lib)
add_dependencies(DrawCubeWithVertexArray glut_draw_cube_with_vertex_array_dll)