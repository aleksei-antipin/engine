
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

target_include_directories(glfw-template PRIVATE ./sol)

### lua
add_library(lua
        lua/lapi.c
        lua/lauxlib.c
        lua/lbaselib.c
        lua/lcode.c
        lua/lcorolib.c
        lua/lctype.c
        lua/ldblib.c
        lua/ldebug.c
        lua/ldo.c
        lua/ldump.c
        lua/lfunc.c
        lua/lgc.c
        lua/linit.c
        lua/liolib.c
        lua/llex.c
        lua/lmathlib.c
        lua/lmem.c
        lua/loadlib.c
        lua/lobject.c
        lua/lopcodes.c
        lua/loslib.c
        lua/lparser.c
        lua/lstate.c
        lua/lstring.c
        lua/lstrlib.c
        lua/ltable.c
        lua/ltablib.c
        lua/ltests.c
        lua/ltm.c
        lua/lua.c
        lua/lundump.c
        lua/lutf8lib.c
        lua/lvm.c
        lua/lzio.c
)
add_library(lua::lua ALIAS lua)

if (WIN32)
    target_compile_definitions(lua PRIVATE LUA_USE_WINDOWS)
endif ()

target_include_directories(lua PUBLIC lua)
if (UNIX)
    target_compile_definitions(lua PRIVATE LUA_USE_LINUX)
    target_link_libraries(lua PRIVATE dl)
endif ()

### sol2
set(SOL2_LUA_VERSION "5.4.7" CACHE STRING "The version of Lua used")
# we build Lua manually
set(SOL2_BUILD_LUA FALSE CACHE BOOL "Always build Lua, do not search for it in the system")
add_subdirectory(sol)

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)