//
// Created by Aleksei Antipin on 17.03.2025.
//

#ifndef IMAGEUTILS_H
#define IMAGEUTILS_H

#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <string>


#include "stb_image.h"
#include "glad/glad.h"

class TextureUtils {
public:
    static unsigned int CreateTexture(const std::string &path, int &width, int &height, int &nrChannels,
                                      int internalFormat, bool flip = false) {
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_set_flip_vertically_on_load(flip);
        unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, internalFormat, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cerr << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
        stbi_set_flip_vertically_on_load(false);

        return texture;
    }
};


#endif //IMAGEUTILS_H
