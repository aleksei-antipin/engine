#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "Shader.h"
#include "Camera/Camera.h"

class Engine {
public:
    double lastTime = 0;

    double deltaTime = 0;

    void Initialize();

    void Run();

    void Terminate();

private:
    int width = 800;
    int height = 600;

    GLFWwindow *window;
    bool isFirmware = false;
    float mixValue = 0.0f;
    Shader shader;
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;

    float rotationX = 0.0f;

    float rotationY = 0.0f;

    float rotationZ = 0.0f;

    unsigned int VBO, VAO, EBO;
    unsigned int texture1, texture2;

    bool isOrtho = false;

    glm::vec4 clear_color;

    glm::mat4 orthoProjection;
    glm::mat4 perspectiveProjection;

    glm::mat4 view;
    glm::mat4 model;
    glm::mat4 projection;

    glm::vec3 objectColor;

    glm::vec3 lightColor;

    Camera camera;

    glm::vec3 lightPos;

    glm::vec3 cubePosition;


    void TickUI();

    void TickUIComplete();

    void TickRender();

    void HandleInput();

    void Tick();

    void UpdateTime();
};
