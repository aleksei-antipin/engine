
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(assimp)
add_subdirectory(entt)

target_include_directories(glfw-template PRIVATE ./glfw/include)
target_include_directories(glfw-template PRIVATE ./glfw/include)

target_include_directories(glfw-template PRIVATE ./glad/include)

target_include_directories(glfw-template PRIVATE ./imgui)
target_include_directories(glfw-template PRIVATE ./imgui/backends)
target_include_directories(glfw-template PRIVATE ./imguizmo)

target_include_directories(glfw-template PRIVATE ./glm)

target_include_directories(glfw-template PRIVATE ./stb)

target_include_directories(glfw-template PRIVATE ./assimp/include)

target_include_directories(glfw-template PRIVATE ./entt/single_include)

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)