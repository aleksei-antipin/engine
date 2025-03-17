//
// Created by Aleksei Antipin on 16.03.2025.
//

#ifndef COLORUTILS_H
#define COLORUTILS_H

#include "glm/glm.hpp"
#include <random>


class ColorUtils {
public:
    // Generate a random color
    static glm::vec4 RandomColor() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<float> dis(0.0f, 1.0f);

        return {dis(gen), dis(gen), dis(gen), 1.0f}; // Fully opaque
    }

    // Predefined colors
    static glm::vec4 Red() { return {1.0f, 0.0f, 0.0f, 1.0f}; }
    static glm::vec4 Green() { return {0.0f, 1.0f, 0.0f, 1.0f}; }
    static glm::vec4 Blue() { return {0.0f, 0.0f, 1.0f, 1.0f}; }
    static glm::vec4 White() { return {1.0f, 1.0f, 1.0f, 1.0f}; }
    static glm::vec4 Black() { return {0.0f, 0.0f, 0.0f, 1.0f}; }

    // Generate grayscale color
    static glm::vec4 Gray(float intensity = 0.5f) {
        return {intensity, intensity, intensity, 1.0f};
    }

    // Generate a color with custom alpha
    static glm::vec4 WithAlpha(const glm::vec4 &color, float alpha) {
        return {color.r, color.g, color.b, alpha};
    }
};
#endif //COLORUTILS_H
