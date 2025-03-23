//
// Created by Aleksei Antipin on 17.03.2025.
//

#ifndef SHADER_H
#define SHADER_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <glad/glad.h>


class Shader {
public:
    unsigned int ID;

    Shader() = default;

    Shader(const char *vertexName, const char *fragmentName);

    void use() const;

    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

    void setVec3(const std::string &name, float x, float y, float z) const;

    void setMat4(const std::string &name, const float *value) const;

private:
};


#endif //SHADER_H
