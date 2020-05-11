add_executable(template_exe)

target_sources(template_exe PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

target_link_libraries(template_exe PRIVATE template)

