//
// Created by Aleksei Antipin on 18.03.2025.
//

#ifndef GLMUTILS_H
#define GLMUTILS_H

#include "glm/glm.hpp"
#include <random>


class GLMUtils {
public:
    static glm::vec3 RandomVec3(float min, float max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<float> dis(min, max);

        return {dis(gen), dis(gen), dis(gen)};
    }


};

#endif //GLMUTILS_H
