#include <sol/sol.hpp>

#include "src/Engine.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::string readScript(const char *name) {
    const auto path = std::string("scripts/") + name;;
    std::string shaderCode;
    std::ifstream shaderFile;

    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        shaderFile.open(path);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderCode = shaderStream.str();
    } catch (const std::exception &e) {
        throw std::runtime_error("Failed to read script: " + path + "\n" + e.what());
    }

    return shaderCode;
}

int main() {
    std::cout << "Hello, from C++\n";
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::package);

    const auto script = readScript("test.lua");

    sol::protected_function_result result = lua.script(script);
    if (!result.valid()) {
        sol::error err = result;
        std::cout << err.what();
    }

    auto *engine = new Engine();
    engine->Initialize();
    engine->Run();
    engine->Terminate();
    return 0;
}
