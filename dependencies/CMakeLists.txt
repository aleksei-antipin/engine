
add_subdirectory(glfw)
add_subdirectory(glad)

target_include_directories(glfw-template PRIVATE ./glfw/include)
target_include_directories(glfw-template PRIVATE ./glfw/include)
target_include_directories(glfw-template PRIVATE ./glad/include)
target_include_directories(glfw-template PRIVATE ./imgui)
target_include_directories(glfw-template PRIVATE ./imgui/backends)

target_include_directories(glfw-template PRIVATE ./glm)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)