cmake_minimum_required(VERSION 3.26)
project(glfw-template)
find_package( OpenGL REQUIRED )
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

)
add_executable(glfw-template ${SOURCES}
        src/Engine.cpp
        src/Engine.h)



target_compile_options(glfw-template PRIVATE -Wall)

add_subdirectory(dependencies)
target_link_libraries(glfw-template PRIVATE glfw glad)
