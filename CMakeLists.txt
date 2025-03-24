cmake_minimum_required(VERSION 3.26)
project(glfw-template)

find_package(OpenGL REQUIRED)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
        "./*.cpp"
        "src/*.cpp"
        "srd/*.h"
        "dependencies/imgui/*.cpp"
        "dependencies/imgui/*.h"
        "dependencies/imgui/backends/imgui_impl_glfw.h"
        "dependencies/imgui/backends/imgui_impl_glfw.cpp"
        "dependencies/imgui/backends/imgui_impl_opengl3.h"
        "dependencies/imgui/backends/imgui_impl_opengl3.cpp"

        "dependencies/imguizmo/*.cpp"
        "dependencies/imguizmo/*.h"

        "dependencies/stb/stb_image.h"
)

add_executable(glfw-template ${SOURCES}
        src/Engine.cpp
        src/Engine.h
        src/Utils/ColorUtils.h
        src/Shader.cpp
        src/Shader.h
        src/Utils/TextureUtils.h
        src/Utils/GLMUtils.h
        src/Camera/Camera.h)

target_compile_options(glfw-template PRIVATE -Wall)

add_subdirectory(dependencies)

target_link_libraries(glfw-template PRIVATE glfw glad assimp EnTT::EnTT)

add_custom_target(copy_shaders ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        ${CMAKE_BINARY_DIR}/shaders
        COMMENT "Copying shaders folder to binary directory"
)


add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
        COMMENT "Copying resources folder to binary directory"
)

add_dependencies(glfw-template copy_shaders)
add_dependencies(glfw-template copy_resources)